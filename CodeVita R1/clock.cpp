#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the position of the hour hand in degrees
double hour_hand_position(int hours, int minutes) {
    return (hours % 12) * 30.0 + minutes * 0.5;
}

// Function to calculate the position of the minute hand in degrees
double minute_hand_position(int minutes) {
    return minutes * 6.0;
}

// Function to calculate the cost of moving the hour hand
int hour_hand_cost(int angle, int A, int B, int X) {
    int clockwise_cost = angle * A * X;
    int counterclockwise_cost = (360 - angle) * B * X;
    return (clockwise_cost < counterclockwise_cost) ? clockwise_cost : counterclockwise_cost;
}

// Function to calculate the cost of moving the minute hand
int minute_hand_cost(int angle, int A, int B, int Y) {
    int clockwise_cost = angle * A * Y;
    int counterclockwise_cost = (360 - angle) * B * Y;
    return (clockwise_cost < counterclockwise_cost) ? clockwise_cost : counterclockwise_cost;
}

int main() {
    int hours, minutes, Q, A, B, X, Y;
    char colon;

    // Read initial time
    scanf("%d%c%d", &hours, &colon, &minutes);

    // Read number of queries
    scanf("%d", &Q);

    // Read costs
    scanf("%d %d %d %d", &A, &B, &X, &Y);

    // Calculate initial positions of the hands
    double initial_hour_position = hour_hand_position(hours, minutes);
    double initial_minute_position = minute_hand_position(minutes);

    int total_cost = 0;

    // Process each query
    for (int i = 0; i < Q; i++) {
        int angle;
        scanf("%d", &angle);

        // Calculate the required movement for the hour and minute hands
        int hour_movement = fabs(angle - initial_hour_position);
        int minute_movement = fabs(angle - initial_minute_position);

        // Adjust the movement if it exceeds 180 degrees to ensure minimum rotation (clockwise or counterclockwise)
        if (hour_movement > 180) hour_movement = 360 - hour_movement;
        if (minute_movement > 180) minute_movement = 360 - minute_movement;

        // Calculate the cost for both hands
        int hour_cost = hour_hand_cost(hour_movement, A, B, X);
        int minute_cost = minute_hand_cost(minute_movement, A, B, Y);

        // Add the minimum cost to the total cost
        total_cost += (hour_cost + minute_cost);
    }

    // Output the total minimum cost
    printf("%d\n", total_cost);

    return 0;
}
