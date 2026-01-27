clear all;
close all;
clc;

% Load image package (for Octave)
pkg load image;

% Read image
img = imread("donkey.jfif");

% Convert to grayscale
grayscale_img = rgb2gray(img);

% Create negative image
negative_img = 255 - grayscale_img;

% Display all images in ONE figure
figure;

subplot(1,3,1);
imshow(img);
title("Original Image");

subplot(1,3,2);
imshow(grayscale_img);
title("Grayscale Image");

subplot(1,3,3);
imshow(uint8(negative_img));
title("Negative Image");

% Save images
imwrite(grayscale_img, "original.jpg");
imwrite(uint8(negative_img), "negative_tan.jpg");


