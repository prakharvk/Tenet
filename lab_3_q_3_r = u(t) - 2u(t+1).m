 %question6
 t = -8:0.01:8;
 ut = t>=0;
 ut1 = t>=-1;
 x = ut-2.*ut1;
 stem(t,x,'r');
 xlabel('time');
 ylabel('amplitude');
 plot(t,x);
 