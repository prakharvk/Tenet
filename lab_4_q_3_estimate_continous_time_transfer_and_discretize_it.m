load iddata1
sys1c = tfest(z1,2);
sys1d = c2d(sys1c,0.1,'zoh');
sys2d = tfest(z1,2,'Ts',0.1);
compare(z1,sys1d,sys2d)