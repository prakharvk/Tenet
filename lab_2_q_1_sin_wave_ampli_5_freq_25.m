clc
close all
clear all
A = 5
F = 25
X = 0:1/1000:1
Y = A * sin(2 * pi * F * X)
figure (1)
plot (X, Y)
xlabel("Time")
ylabel("Amplitude")
title("sine wave")