% F(a) = P(x<=a)
% F(a) = P(x<=a) = P(x<a)
% PDF pt functia de probabilitate
% CDF pt functie de repartitie

% 'Normal' - Normal
% 't' - Student
% 'chiz'
% 'f' - Fischer

clear all
clc

m = 0;
s = 1;
n = 12;

% a)
% P(x<=0) = F(0) <- CDF
% P(x>=0) = 1 - P(x<0) = 1 - F(0)
a1n = cdf('Normal', 0, m, s);
a1t = cdf('t', 0, n);

fprintf('a)\n');
fprintf(' Normal:\n');
fprintf(' P(x<=0) = %f\n',a1n);
fprintf(' P(x>=0) = %f\n',1-a1n);
fprintf('Student:\n');
fprintf(' P(x<=0) = %f\n',a1t);
fprintf(' P(x>=0) = %f\n',1-a1t);

% b)
% P(-1<=x<=1) = 1 - P(-1<x<1)
% P(x<=-1 or x>=1) = 1 - P(-1<x<1)

b1n = cdf('Normal', 1, m, s) - cdf('Normal', -1, m, s);
fprintf('\nb)');
fprintf('Normal \n');
fprintf('P(-1<=x<=1) = %f\n',b1n);
fprintf('P(x<=-1 or x>=1) = %f\n',1 -b1n);

% .... TO DO Student

% c)
% 0 < alfa < 1 - given 
% P(x<x_alpha) = F(x_alpha) = alpha.
%                  x_alpha = F^(-1)(alpha) -> ICDF

alpha = 0.35;
xalpha = icdf('Normal', alpha, m, s);
fprintf('\nc)')
fprintf('Normal \n');
fprintf('Quantitile of order %f is %f\n', alpha, xalpha);

% d)
% P(x>x_beta) = beta
% 1 - P(x<=x_beta) = beta
% P(x<=x_beta) = 1 - beta
% F(x_beta) = 1 - beta
% x_beta = F^(-1)*(1-beta)

fprintf('\nd)\n')
beta = 0.25;
xbeta = icdf('Normal',1 - beta, m, s);
fprintf('Normal \n');
fprintf('Quantile of order %f is %f\n', 1-beta, xbeta);