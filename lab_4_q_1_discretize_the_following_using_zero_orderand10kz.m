h = tf([10],[1 3 10],'IODelay',0.25); 
hd = c2d(h,0.1);
step(h,'--',hd,'-');