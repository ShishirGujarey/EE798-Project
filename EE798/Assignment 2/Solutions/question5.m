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
variancedB=[-20 -15 -10 -5 0];
variancedB=variancedB*(1/10);
variance=10.^variancedB;
for iterate=1:length(variancedB)
    stdev=sqrt(variance(iterate));
    error=stdev*randn(n,1);
    t=phi*w + error;
    A=100*eye(m);
    sigma_old=inv( ( phi' * phi/variance(iterate) ) + A );
    mu_old=(sigma_old * phi' * t)/variance(iterate);
    for j = 1:10000
       A=diag(diag(eye(m)- A* diag(diag(sigma_old))));
       A= A * diag( mu_old.^-2 );
       sigma_new=inv( ( phi' * phi/variance(iterate) ) + A );
       mu_new=(sigma_new * phi' * t)/variance(iterate);
       if( ((norm(mu_old - mu_new))/norm(mu_old))^2 < 1e-03 )
               break;
       end
       mu_old=mu_new;
       sigma_old=sigma_new;    
    end
    w_map=mu_new;
    nmse(iterate)=(norm(w_map-w)/norm(w))^2;
end
plot(variancedB*10,nmse,'o',MarkerFaceColor='b');
xlabel("Noise Variance");
ylabel("NMSE");
grid on;
