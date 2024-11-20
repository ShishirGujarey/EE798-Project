%% Generating Data Set
clear all;close all;

mean1 = [3 3]';
mean2 = [1 -3]';
covariance1 = [1 0 ; 0 2];
covariance2 = [2 0 ; 0 1];
pi1 = 0.8;
pi2 = 0.2;
X = [];
for n = 1:500
if(rand<pi1)
X(n,:) = mvnrnd(mean1,covariance1,1);
else
X(n,:) = mvnrnd(mean2,covariance2,1);
end
end
%% Initilaise the mixture parameters
PredictedMean1 = randn(1,2);
PredictedMean2 = randn(1,2);
PredictedCovariance1 = rand*eye(2,2);
PredictedCovariance2 = rand*eye(2,2);
PredictedPrior1 = 0.5;
PredictedPrior2 = 0.5;

%% EM Algorithm

N = 500;
converge = 0.01;
q(:,1) = rand(500,1);
q(:,2) = ones(500,1)-q(:,1);
LowerBound(1) = -inf;
for i = 1 : 100

logProb1 = -log(2*pi) - 0.5*log(det(PredictedCovariance1)) ...
- 0.5 * diag( (X - PredictedMean1 ) * inv(PredictedCovariance1) ...
*(X - PredictedMean1 )' );

logProb2 = -log(2*pi) - 0.5*log(det(PredictedCovariance2)) - 0.5 * ...
diag( (X - PredictedMean2 ) * inv(PredictedCovariance2) ...
*(X - PredictedMean2 )' );

% Calculate Lower Bound for current iteration, and check if it has
% converged
if i>1
LowerBound(i) = sum( q(: , 1)* log(PredictedPrior1) ) + sum( q(: , 2)* log(PredictedPrior2) ) ...
+ sum(q(: , 1) .* logProb1) + sum(q(: , 2) .* logProb2) ...
- sum( sum (q .* log (q) ) ) ;
if abs(LowerBound(i)-LowerBound(i-1))<converge
break
end
end

% Update q_nk first, since this would be used in the subsequent
% Calculations of pi/mu/sigma. Division by 0 is prohibited.
q(: , 1) = PredictedPrior1 * exp(logProb1);
q(: , 2) = PredictedPrior2 * exp(logProb2);
q(q<1e-60) = 1e-10;
q(q>1-1e-60) = 1e-10;
q= q./[sum(q,2) sum(q,2)];

% Update pi_k
MeanTemp = mean(q,1);
PredictedPrior1=MeanTemp(1);
PredictedPrior2=MeanTemp(2);

% Update mu_k
PredictedMean1 = sum(X.*[q(:,1) q(:,1)],1)./ sum(q(:,1));
PredictedMean2 = sum(X.*[q(:,2) q(:,2)],1)./ sum(q(:,2));

% update sigma_k
PredictedCovariance1 = ( ( X - PredictedMean1 ).*[q(:,1) q(:,1)])'*( X - PredictedMean1 )./sum(q(:,1));
PredictedCovariance2 = ( ( X - PredictedMean2 ).*[q(:,2) q(:,2)])'*( X - PredictedMean2 )./sum(q(:,2));

% %% Plot the current status
% figure(2);hold off
% for n = 1:N
% if(q(n,1)>q(n,2))
% plot(X(n,1),X(n,2),'ko','markerfacecolor','r');
% else
% plot(X(n,1),X(n,2),'ko','markerfacecolor','g');
% end
% hold on
% end
% [A,C] = meshgrid(-10:0.1:10,-10:0.1:10);
% Z = mvnpdf([A(:) C(:)],PredictedMean1,PredictedCovariance1);
% Z = reshape(Z,size(A));
% contour(A,C,Z);
%
% [A,C] = meshgrid(-10:0.1:10,-10:0.1:10);
% Z = mvnpdf([A(:) C(:)],PredictedMean2,PredictedCovariance2);
% Z = reshape(Z,size(A));
% contour(A,C,Z);
% ti = sprintf('After %g iterations',i);
% title(ti)
end
%% Note that we are starting randomly. It might be possible that 1 and 2 get interchanged

if PredictedPrior1<PredictedPrior2
temp=PredictedPrior1;PredictedPrior1=PredictedPrior2;PredictedPrior2=temp;
temp=PredictedCovariance1;PredictedCovariance1=PredictedCovariance2;PredictedCovariance2=temp;
temp=PredictedMean1;PredictedMean1=PredictedMean2;PredictedMean2=temp;
temp=q(:,1);q(:,1)=q(:,2);q(:,2)=temp;
end

%% Plot the final status:

figure(3);hold off
for n = 1:N
if(q(n,1)>q(n,2))
plot(X(n,1),X(n,2),'ko','markerfacecolor','r');
else
plot(X(n,1),X(n,2),'ko','markerfacecolor','g');
end
hold on
end
[A,C] = meshgrid(-10:0.1:10,-10:0.1:10);
Z = mvnpdf([A(:) C(:)],PredictedMean1,PredictedCovariance1);
Z = reshape(Z,size(A));
contour(A,C,Z);

[A,C] = meshgrid(-10:0.1:10,-10:0.1:10);
Z = mvnpdf([A(:) C(:)],PredictedMean2,PredictedCovariance2);
Z = reshape(Z,size(A));
contour(A,C,Z);
title('The final result is as follows: Red=1, Green=2')