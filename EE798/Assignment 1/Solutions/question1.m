clc; clear all; close all;
N=200;
w0=1; w1=-2; w2=0.5;
n=randn(N,1);
x=sort(-5+10*rand(N,1));
t=2-2*x+0.5*x.^2+n;
%% Part 1: Data Set:

figure(1);
hold off;
scatter(x,t,35,'o','MarkerEdgeColor','Black','MarkerFaceColor','Blue','LineWidth',1.25);
title('Data Set');
xlabel('Olympic Year');
ylabel('Winning Time');
xlim([-8 8]);
grid on;

%% Part 2: Linear Model:

hold off;

MeanX=sum(x)/N;
MeanT=sum(t)/N;
MeanXT=sum(x.*t)/N;
MeanXX=sum(x.*x)/N;

w1L=(MeanXT-MeanX*MeanT)/(MeanXX-MeanX*MeanX);
w0L=MeanT-w1L*MeanX;

figure(2);
hold on;
scatter(x,t,40,'o','MarkerFaceColor','Cyan');
title('Linear Fit Model');
xlabel('Olympic Year');
ylabel('Winning Time');
xlim([-8 8]);
hold on;
plot([-8 8], w0L+w1L*[-8 8],'r','linewidth',2);
grid on;


%% Part 3: Quadratic+Linear Model:

hold off;
beta=ones(200,1);
X=[beta';x';(x.^2)']';
QTime=inv(X'*X)*X'*t;
xaxis = [-8:0.01:8]';
quad = [];
for k = 0:2
   quad = [quad xaxis.^k];
end
figure(3);
hold on;
scatter(x,t,40,'o','MarkerFaceColor','Cyan');
title('Quadratic Fit Model');
xlabel('Olympic Year');
ylabel('Winning Time');
xlim([-8 8]);
hold on;
plot([-8 8], w0L+w1L*[-8 8],'g','linewidth',0.5);
plot(xaxis,quad*QTime,'r','linewidth',2);
legend('Data','Linear','Quadratic');
grid on;



