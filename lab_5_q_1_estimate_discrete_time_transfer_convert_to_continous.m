load iddata1
sys1d = tfest(z1,2,'Ts',0.1);
sys1c = d2c(sys1d,'zoh');
sys2c = tfest(z1,2);
compare(z1,sys1c,sys2c)