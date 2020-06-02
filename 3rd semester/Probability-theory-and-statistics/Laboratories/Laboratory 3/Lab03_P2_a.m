clear all
clc
close all

n = 30;
p = 0.65;
k = 0 : n;
y = pdf('bino',k,n,p);

figure(1)
hold on
bar(k,y);

mu = n * p;
sig = sqrt(n * p * (1-p));
x = mu - 3 * sig : 0.01 : mu + 3 * sig;
z = pdf('Normal', x, mu, sig);

plot(x, z, 'Color', 'r', 'LineWidth', 2);