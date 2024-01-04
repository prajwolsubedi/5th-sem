ori=imread('img/redrose.jpg');
gray=rgb2gray(ori);
binary=gray;
[r,c]=size(binary);

for i=1:r
    for j=1:c
        f=binary(i,j);
        if f<=127
          binary(i,j)=0;
        elseif f>127 && f<256
          binary(i,j)=255;
        end 
    end
end

figure;
subplot(2,2,1);imshow(ori);title('Original Image');
subplot(2,2,2);imshow(gray);title('gray Image');
subplot(2,2,3);imshow(binary);title('binary Image');
