clc
close all
clear all
A = 5
F = 25
X = 0:1/100:1
Y = A * cos(2 * pi * F * X)
figure (2)
plot (X, Y)
xlabel ("Time")
ylabel("Amplitude")
title("cos wave")