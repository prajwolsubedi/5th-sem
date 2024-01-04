ori_img = imread('img\redrose.jpg');
noisy_img = ori_img;
x = rand(size(noisy_img));
noisy_img(x(:)>0.95)=255; %adding salt noise
minf = @(x)min(x(:));
filtered_img = nlfilter(noisy_img,[3,3],minf);
subplot(2,2,1);imshow(ori_img); title('Original Image');
subplot(2,2,2);imshow(noisy_img); title('Image with salt noise');
subplot(2,2,3);imshow(filtered_img); title('Filtered Image');