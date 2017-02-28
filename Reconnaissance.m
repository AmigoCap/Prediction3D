Model = imread('Modele.bmp');
Model = double(Model);

I = imread('11Cal01modReady.bmp');
VI = double(I(:));

a = 0.0001;

Prob = exp(a*(Model*VI))./(1+exp(a*(Model*VI)));

NormProb = Prob./sum(Prob);
