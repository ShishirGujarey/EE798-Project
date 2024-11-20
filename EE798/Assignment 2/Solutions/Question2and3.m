clc; clear all; close all;
n=20;
m=40;
d0=7;
phi=randn(n,m);
p=randperm(m);
w=randn(m,1);
for i = 1:m-d0
    w(p(i))=0;
end
fprintf("Design Matrix is:");
phi
fprintf("\n\n Sparse weight vector w is:")
w
variancedB=[-20 -15 -10 -5 0];
variancedB=variancedB*(1/10);
variance=10.^variancedB
for iterate=1:length(variancedB)
    stdev=sqrt(variance(iterate));
    error=stdev*randn(n,1);
    fprintf("Observations (t) corresponding to noise variance %f is:", variance(iterate));
    t=phi*w + error
end


