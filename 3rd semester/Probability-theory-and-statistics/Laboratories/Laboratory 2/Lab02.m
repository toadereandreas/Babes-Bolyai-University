close all;
n=3;
p = 0.5;
k = 0:n;
y = pdf('bino',k,n,p);
z = cdf('bino',k,n,p);
figure(1);
hold on;
plot(k,y,'b*');
figure(2);
plot(k,z,'ro');
figure(3);
stairs(k,z);

%c
c1 = pdf('bino',0,n,p);
c2 = 1 - pdf('bino',1,n,p);

%d
d1 = cdf('bino',2,n,p);
d2 = cdf('bino',1,n,p);

%e
e1 = 1-cdf('bino',0,n,p);
e2 = 1-cdf('bino',1,n,p);

%f
N = 10;
A = rand(3,N)
A < 0.5
x = sum( A < 0.5 )
v(1)= sum(x==0)/N
v(2)= sum(x==1)/N
v(3)= sum(x==2)/N
v(4)= sum(x==3)/N
figure(1)
plot(k,v,'ro');