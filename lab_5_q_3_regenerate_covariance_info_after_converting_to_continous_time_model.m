load iddata1
sysd = tfest(z1,2,'Ts',0.1);
sysc = d2c(sysd,'zoh');
opt = tfestOptions; 
opt.SearchOptions.MaxIterations = 0;
sys1c = tfest(z1,sysc,opt);
h = bodeplot(sysd,sys1c);
showConfidence(h,3)