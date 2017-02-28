close all;
clear all;

Un = imread('11Cal02modReady.bmp');
Trois = imread('1Cal04modReady.bmp');

VUn = double(Un(:));
VTrois = double(Trois(:));

M = [VUn VTrois];

Npop = 10;

P = -0.0001+0.0002*rand(size(M,2), size(M,1), Npop);

a = 0.0001;

Ms = zeros(size(M, 2), size(M, 2), Npop);
err = zeros(Npop,1);

it = 1000;

MeilleurErr2 = Inf;
Merr = zeros(it,1);

for j = 1:it
    j;
    for i = 1:Npop
        [Ms(:,:,i) err(i)] = PB4(P(:,:,i), M, a);
    end
    
    [err I] = sort(err, 'descend');
    P = P(:,:,I);
    
    MeilleurErr1 = err(10);
    MeilleurErr2 = min(MeilleurErr1, MeilleurErr2);
    Merr(j) = MeilleurErr2;
    if MeilleurErr2 == MeilleurErr1
        MeilleurPoids = P(:,:,10);
    end
    
    % choix aleatoire des elements pour la grande mutation 
    eGM = ceil(size(P, 1)*size(P, 2)*rand(floor(Npop/3),1));
    
    s = [size(P, 1), size(P, 2)];
    
    [I,J] = ind2sub(s, eGM);

    for k = 1:floor(Npop/4)
        P(I(k),J(k),k) = -10+20*rand;
    end
    
    % choix aleatoire pour la petite mutation
    ePM = ceil(size(P, 1)*size(P, 1)*rand(floor(Npop - Npop/2),1));
    
    [I,J] = ind2sub(s, ePM);
    
    e = 0.000001;

    for k = 1:floor(Npop - Npop/2)
        if k ~= 1
            P(I(k),J(k),Npop-k) = P(I(k),J(k),10)-e+2*e*rand;
        else
            P(I(k),J(k),Npop-k) = P(I(k),J(k),Npop-k)-e+2*e*rand;
        end
    end
    
    % crossover
    for k = floor(Npop/4):floor(Npop/2)
        P(:,:,k) = (P(:,:,k) + MeilleurPoids(:,:))/2;
    end
    
 
end

figure,
subplot(1,2,1), plot(Merr);
subplot(1,2,2), bar3(exp(a*(MeilleurPoids*M))./(1+exp(a*(MeilleurPoids*M))));

MeilleurErr2

imwrite(MeilleurPoids, 'Modele.bmp');