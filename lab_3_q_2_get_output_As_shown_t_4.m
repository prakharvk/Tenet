
 %question5
 subplot(2,1,1);
 t = 0:0.01:8;
 x =  t>=4;
 stem(t,x,'r');
 xlabel('time');
 ylabel('amplitude');
 plot(t,x);
 
 subplot(2,1,2);
 t = 0:0.01:8;
 x =  (t>=4).*(t-4);
 stem(t,x,'r');
 xlabel('time');
 ylabel('amplitude');
 plot(t,x);
 
 
 



 