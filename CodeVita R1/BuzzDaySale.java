import java.util.*;

public class BuzzDaySale {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ids = new int[n];
        int[] costs = new int[n];
          // Read IDs
    for (int i = 0; i < n; i++) {
        ids[i] = sc.nextInt();
    }
    
    // Read costs
    for (int i = 0; i < n; i++) {
        costs[i] = sc.nextInt();
    }
    
    int budget = sc.nextInt();
    int[] result = solve(n, ids, costs, budget);
    
    // Use print instead of println to avoid an extra newline
    System.out.print(result[0] + " " + result[1]);
}

static int[] solve(int n, int[] ids, int[] costs, int budget) {
    Map<Integer, Integer> costMap = new HashMap<>();
    for (int i = 0; i < n; i++) {
        costMap.put(ids[i], costs[i]);
    }

    int maxFreeItems = 0;
    int maxWorth = 0;

    // Iterate over each item
    for (int i = 0; i < n; i++) {
        int currentCost = costs[i];
        if (currentCost > budget) continue;

        int maxQuantity = budget / currentCost;
        int freeItems = 0;
        int worth = 0;

        // Check for items that can be taken for free
        for (int j = 0; j < n; j++) {
            if (i != j && ids[i] % ids[j] == 0) {
                freeItems += maxQuantity;  // We get maxQuantity of free items
                worth += costMap.get(ids[j]) * maxQuantity;  // Add worth of free items
            }
        }

        // Check if this configuration is better
        if (freeItems > maxFreeItems) {
            maxFreeItems = freeItems;
            maxWorth = worth;
        } else if (freeItems == maxFreeItems) {
            maxWorth = Math.max(maxWorth, worth);
        }
    }
    
    return new int[]{maxFreeItems, maxWorth};
}
}
