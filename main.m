clear all;
close all;

filename = '11Cal01mod.csv';

M = csvread(filename);
M(:,1) = (1:size(M,1));
Doigt = M(:,3:5);
minimum = min(Doigt);
Doigt = Doigt - minimum;
Doigt = int16(floor(Doigt))+1;
maximum = max(Doigt);
maximum = 2*round(maximum/2);
image = zeros(maximum(1), maximum(2));

for i = 1:size(Doigt,1)
    image(Doigt(i, 1), Doigt(i, 2)) = 1;
end

image = image';
padver = (200-size(image,1))/2;
padhor = (100-size(image,2))/2;

image = padarray(image, [padver,padhor]);
se = strel('disk', 7, 4);
imagedil = imdilate(image, se);

imshow(imagedil);

C = strsplit(filename, '.');
filename_to_write = strcat(C{1}, 'Ready.bmp');

imwrite(imagedil, filename_to_write);



