ori_img = imread('img/redrose.jpg');
new_img = ori_img;
s1 = 20;
s2 = 150;
r1 = 100;
r2 = 150;
L = 256;
alfa = s1/r1;
beta = (s2-s1)/(r2-r1);
gamma = ((L-1)-s2)/((L-1)-r2);
[x,y,z] = size(new_img);
for i=1:x
 for j=1:y
 for k=1:z
 if new_img(i,j,k)<=r1
 r = new_img(i,j,k);
 new_img(i,j,k) = alfa*r;
 elseif new_img(i,j,k)>r1 && new_img(i,j,k)<=r2
 r = new_img(i,j,k);
 new_img(i,j,k) = (beta*(r-r1))+s1;
 else
 r = new_img(i,j,k);
 new_img(i,j,k) = (gamma*(r-r2)+s2);
 endif
 endfor
 endfor
endfor
figure;
subplot(1,2,1); imshow(ori_img); title('Original Image');
subplot(1,2,2); imshow(new_img); title('Enhanced Image');