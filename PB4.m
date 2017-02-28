function [ Ms, err ] = PB4( Poids, M, a)
    Ms = exp(a*(Poids*M))./(1+exp(a*(Poids*M)));
    I = eye(size(Ms));
    err = sum(sum((Ms-I).^2));
end