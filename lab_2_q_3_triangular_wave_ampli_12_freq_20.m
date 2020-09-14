clc
close all
clear all
A = 12
F = 20
X = 0:1/1000:1
Y = A * sawtooth(2 * pi * F * X, 0.5)
figure (3)
plot (X, Y)
xlabel ("Time")
ylabel("Amplitude")
title("Trangular Wave")