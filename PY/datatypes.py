x=50
y=60.6
z=True
a=[20,30,45]
q="aditya"
r=("geeks","for")
t=set("abhisar")
d={1:'state',2:'city',3:'town'}
d1=dict({1:'state',2:'city',3:'town'})
d={1:'state','name':'city',3:'town'}
print(type(x))
print(type(y))
print(type(z))
print(type(a))
print(type(q))
print(type(r))
print(type(t))
print(q[1])
print(q[2])
print(q[-1])
print(q[-2])
print(t)
print(r[1])
print(r[0])
print(r)
#Sorted Set
print(sorted(t))
print(type(True))
for i in t:
     print(i,end=" ")
#check if item exist or not
print("geeks" in t) 

print(d)
print(d1)
print(d['name'])
print(d.get(3))