ori=imread('img/redrose .jpg');
double_img=im2double(ori);
new_img=double_img;
[row,col]=size(ori);
c=10;
for i=1:row
    for j=1:col
        new_img(i,j)=c*log(1+double_img(i,j));
     end
end


figure;
subplot(1,2,1);imshow(ori);title('Original Image');
subplot(1,2,2);imshow(new_img);title('log transformation');
