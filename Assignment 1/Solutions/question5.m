clc; clear all; close all;
N=100;
n=300*randn(N,1);
x=sort(-5+10*rand(N,1));
t=5*x.^3-x.^2+x+n;

figure(1);
hold off;
scatter(x,t,25,'o','MarkerEdgeColor','Black','MarkerFaceColor','Blue','LineWidth',1.25);
title('Data Set');
xlabel('Olympic Year');
ylabel('Winning Time');
xlim([-8 8]);
grid on;

%% Part 1: Linear Model
X=[];
linear=[];
xaxis=[-5:0.1:5]'
for k= 0:1
    X=[X x.^k];
    linear=[linear xaxis.^k];
end
w=inv(X' * X) * X' * t;
var=(t' * t - t' * X * w)/N;
var_new=var*diag(linear * inv(X' * X) * linear');
figure(2);
hold off;
scatter(x,t,25,'o','MarkerFaceColor','Cyan');
title('Linear Fit Model');
xlabel('Olympic Year');
ylabel('Winning Time');
hold on;
errorbar(xaxis,linear*w,var_new,'r','LineWidth',2)
xlim([-8 8]);
grid on;

%% Part 2: Cubic Model
X=[];
cubic=[];
xaxis=[-5:0.1:5]'
for k= 0:3
    X=[X x.^k];
    cubic=[cubic xaxis.^k];
end
w=inv(X' * X) * X' * t;
var=(t' * t - t' * X * w)/N;
var_new=var*diag(cubic * inv(X' * X) * cubic');
figure(3);
hold off;
scatter(x,t,25,'o','MarkerFaceColor','Cyan');
title('Cubic Fit Model');
xlabel('Olympic Year');
ylabel('Winning Time');
hold on;
errorbar(xaxis,cubic*w,var_new,'r','LineWidth',2)
xlim([-8 8]);
grid on;

%% Part 3: Sixth-Order Model
X=[];
sixth=[];
xaxis=[-5:0.1:5]'
for k= 0:5
    X=[X x.^k];
    sixth=[sixth xaxis.^k];
end
w=inv(X' * X) * X' * t;
var=(t' * t - t' * X * w)/N;
var_new=var*diag(sixth * inv(X' * X) * sixth');
figure(4);
hold off;
scatter(x,t,25,'o','MarkerFaceColor','Cyan');
title('Sixth Fit Model');
xlabel('Olympic Year');
ylabel('Winning Time');
hold on;
errorbar(xaxis,sixth*w,var_new,'r','LineWidth',2)
xlim([-8 8]);
grid on;




