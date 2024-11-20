clc; clear all; close all;
x=[0:0.2:1]';
n=3*randn(6,1);
t=2*x-3+n;
xaxis=[-0.15: 0.1: 1.15]';
xvar=[];
X=[];
for i= 0:5
    xvar=[xvar xaxis.^i];
    X=[X x.^i];
end

%% Part 1: Data Set

figure(1);
hold off;
scatter(x,t,35,'o','MarkerEdgeColor','Black','MarkerFaceColor','Blue','LineWidth',1.25);
title('Data Set');
xlabel('Olympic Year');
ylabel('Winning Time');
xlim([-0.15 1.15]);
grid on;

%% Part 2: Fifth Order Polynomial fit: Lambda=0

    hold off
    w=inv(X' * X ) * X' * t;
    figure(2); hold off
    scatter(x,t,35,'o','MarkerEdgeColor','Black','MarkerFaceColor','Blue','LineWidth',1.25);
    hold on;
    plot(xaxis, xvar*w,'g','linewidth',0.5);
    xlim([-0.15 1.15]);
    grid on;
    title('Polynomial Fit: No regularization');
    xlabel('Olympic Year');
    ylabel('Winning Time');
    grid on;

%% Part 3: Fifth Order Polynomial fit: Lambda=10^-6

    hold off
    w=inv(X' * X + 6 * 1e-6 * eye(size(X,2))) * X' * t;
    figure(3); hold off
    scatter(x,t,35,'o','MarkerEdgeColor','Black','MarkerFaceColor','Blue','LineWidth',1.25);
    hold on;
    plot(xaxis, xvar*w,'g','linewidth',0.5);
    xlim([-0.15 1.15]);
    grid on;
    title('Polynomial Fit: Regularization constant lambda= 10^-6');
    xlabel('Olympic Year');
    ylabel('Winning Time');
    grid on;

%% Part 4: Fifth Order Polynomial fit: Lambda=0.01

    hold off
    w=inv(X' * X + 6 * 0.01 * eye(size(X,2))) * X' * t;
    figure(4); hold off
    scatter(x,t,35,'o','MarkerEdgeColor','Black','MarkerFaceColor','Blue','LineWidth',1.25);
    hold on;
    plot(xaxis, xvar*w,'g','linewidth',0.5);
    xlim([-0.15 1.15]);
    grid on;
    title('Polynomial Fit: Regularization constant lambda= 0.01');
    xlabel('Olympic Year');
    ylabel('Winning Time');
    grid on;

%% Part 5: Fifth Order Polynomial fit: Lambda=0.1

    hold off
    w=inv(X' * X + 6 * 0.1 * eye(size(X,2))) * X' * t;
    figure(4); hold off
    scatter(x,t,35,'o','MarkerEdgeColor','Black','MarkerFaceColor','Blue','LineWidth',1.25);
    hold on;
    plot(xaxis, xvar*w,'g','linewidth',0.5);
    xlim([-0.25 1.25]);
    grid on;
    title('Polynomial Fit: Regularization constant lambda= 0.1');
    xlabel('Olympic Year');
    ylabel('Winning Time');
    grid on;
    


