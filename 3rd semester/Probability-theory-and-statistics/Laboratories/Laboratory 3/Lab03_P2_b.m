clear all
clc
close all

n = 30;
p = 0.05;
k = 0 : n;
lamda = n * p;
y = pdf('bino',k,n,p);
z = pdf('poiss',k,lamda);

figure(1)
bar(k,y,'b');
figure(2)
bar(k,z,'r');
figure(3)
bar(k,[y',z']); %[ ] pentru a pune doua grafice in aceeasi figura