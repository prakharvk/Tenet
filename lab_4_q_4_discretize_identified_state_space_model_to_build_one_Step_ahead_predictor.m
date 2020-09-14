load iddata2
sysc = ssest(z2,4);
predict(sysc,z2);
sysd = c2d(sysc,0.1,'zoh');
[A,B,C,D,K] = idssdata(sysd);
Predictor = ss(A-K*C,[K B-K*D],C,[0 D],0.1);
lsim(Predictor,[z2.y,z2.u]);