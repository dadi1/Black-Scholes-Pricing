////////////////////////////////////////////
// D efi n e c o n s t a n t s
///////////////////////////////////////////
E = %e ;
T = 1 ; // one yea r
S0 = 1 ; // i n i t i a l s ha r e val u e
K = 1 . 0 ; // s t r i k e p r i c e
r = 0 . 5 ; // r i s k f r e e r a t e
s i g = 0 . 3 ; // annual v o l a t i l i t y
N = 3 0; // t r a di n g days with
dt = T/N;
// Time to ma tu ri ty [ T0 , . . . ]
Tau = T*( one s (N, 1 ) − dt * [ 0 :N−1] ’ );
N W = N+1;
////////////////////////////////////////////
// Get co n v e ni e n t normal f u n c ti o n
///////////////////////////////////////////
f u n c ti o n [ c df ]= normcdf ( x )
cdfN = l e n g t h ( x ) ;
c df = c df no r (”PQ” , x , z e r o s ( 1 , cdfN ) , one s ( 1 , cdfN ) ) ;
// Mean ze ro , sigma=1
e n df u n c tio n
%
%/////////////////////////////////////
%// Compute c a l l f o r a l l time s
%/////////////////////////////////////
%f u n c ti o n [ v , N1, N2]= Call1 ( S ,K, r , sigma , tau ) ;
% // tau = T−t Time z e ro i s t =0, tau=T
% d1=( l o g ( S/K)+( r +0.5* sigma ˆ2 )* tau ) . / ( sigma * s q r t ( tau ) ) ;
% d2=( l o g ( S/K)+( r −0.5* sigma ˆ2 )* tau ) . / ( sigma * s q r t ( tau ) ) ;
% N1=normcdf ( d1 ) ; N2=normcdf ( d2 ) ;
% v=S . *N1−K*exp(−r * tau )*N2 ;
%e n df u n c tio n
%
%/////////////////////////////////////
// Compute c a l l f o r a l l time s [ 0 ,T]
/////////////////////////////////////
f u n c ti o n [ v , N1, N2 ] = Call2 ( SS ,K, r , sigma , Tau ) ;
// tau = T−t Time z e ro i s t =0, tau=T
// pc=1 f o r c a l l and −1 f o r put
R = r * one s ( l e n g t h ( SS ) , 1 ) ;
Sigma = sigma * one s ( l e n g t h ( SS ) , 1 ) ;
d1=( l o g ( SS/K)+(R+0.5*Sigma ˆ 2 ) . * Tau ) . / ( Sigma . * s q r t (Tau ) ) ;
d2=( l o g ( SS/K)+(R−0.5*Sigma ˆ 2 ) . * Tau ) . / ( Sigma . * s q r t (Tau ) ) ;
N1 = z e r o s ( l e n g t h ( SS ) , 1 ) ; N1 = N1 ;
f o r i =1: l e n g t h ( SS ) ; N1( i )=normcdf ( d1 ( i ) ) ; N2( i )=normcdf ( d2 ( i ) ) ; endv=SS . *N1−K*(%eˆ(−R. * Tau ) . *N2 ) ;
// pause
e n df u n c tio n
//////////////////////////////////////////////
// Compute v a n i l l a p r i c e s f o r a l l time s
/////////////////////////////////////////////
f u n c ti o n [ v , N1, N2]= V a nill a ( SS ,K, r , sigma , Tau , pc ) ;
// tau = T−t Time z e ro i s t =0, tau=T
// pc=1 f o r c a l l and −1 f o r put
R = r * one s ( l e n g t h ( SS ) , 1 ) ;
Sigma = sigma * one s ( l e n g t h ( SS ) , 1 ) ;
d1 = ( l o g ( SS/K)+(R+0.5*Sigma ˆ 2 ) . * Tau ) . / ( Sigma . * s q r t (Tau ) ) ;
d2 = ( l o g ( SS/K)+(R−0.5*Sigma ˆ 2 ) . * Tau ) . / ( Sigma . * s q r t (Tau ) ) ;
N1 = z e r o s ( l e n g t h ( SS ) , 1 ) ; N1 = N1 ;
f o r i =1: l e n g t h ( SS ) ;
N1( i ) = normcdf ( d1 ( i ) ) ;
N2( i ) = normcdf ( d2 ( i ) ) ;
end
i f pc == −1 then
N1 = one s ( l e n g t h ( SS ) ,1) − N1 ;
N2 = one s ( l e n g t h ( SS ) ,1) − N2 ;
end
v = pc *( SS . *N1−K*(%eˆ(−R. * Tau ) . *N2 ) ) ;
e n df u n c tio n
//////////////////////////////////////////////
// I n i t i a l i z e v a r i a b l e s
/////////////////////////////////////////////
S=z e r o s (N W, 1 ) ; hedge=S ; borrow=S ; val u e=S ; KK=S ;
// Get time s and i n t e r e s t bonds
TT = [ 0 : T/N:T] ’ ; // Time from 0 to T
Ttau = [T:−T/N: 0 ] ’ ; // Time to ma tu ri ty = tau
B = %e ˆ [ r *TT] ; //R=%e ˆ [ ( rf −s i g ˆ2/2 )*TT] ; [ R1−R] ,
//////////////////////////////
//////////////////////////////////////////////////////
// Generate Wiener path f o r our a s s e t
// with Wiener a c r e s cim o s
///////////////////////////////////////
// Get r a t e f o r a l l time s
R = %e ˆ [ ( r−s i g ˆ2/2 )*TT] ;
R1 = %e ˆ [ r *T ] ; [ R1−R] ,
// Choose s e e d f o r random number g e n e r a t o r
I s = 1355;
grand (” s e t s d ” , I s +3);
// Get Wiener i n c r em e n t s
dW = grand (N, 1 , ” nor ” , 0 , 1 ) ;
W = ( s i g * [ 0 ; cumsum (dW) ] ) ;
// Get a s s e t f o r a l l time s
S t = S0 *(R. *EˆW) ; cl e a n ( S t ) ;
///////////////////////////////////////////////////////
// Get o p tio n v al u e s
/////////////////////////////////////////////
// [ c0 , N1, N2 ] = Call1 ( S0 ,K, r , si g ,T ) ;
[ c t , N1 t , N2 t ] = Call2 ( S t ,K, r , si g , Ttau ) ; // TT
// put
// [ p t , n1 t , n2 t ] = V a nill a ( S t ,K, r , si g , Ttau ,−1)
////////////////////////
// Show
di s p ( ’ S t , c t , N1 t , N2 t , Ttau ,TT’ )
[ S t , c t , N1 t , N2 t , Ttau ,TT]
//
// I n i t i a l i z e
l l = l e n g t h ( S t )
Po r tof =z e r o s ( l l , 1 ) ; hedge=Po r tof ; p s i=Po r tof ;
// At t=0
s = S t ( 1 ) ;
[ Ttau ( 1 , S t ( 1 ) ] ,
D1 = N1 t ( 1 ) ; // compute Del ta f o r c a l l o p tihedge ( 1 ) = D1*S0 ; // i n i t i a l hedge : amount of s tp s i ( 1 ) = c t ( 1 ) − hedge ( 1 ) ; // borrow money f o r hedge
Po r tof ( 1 ) = D1*S0 + B(1 ) * p s i ( 1 ) ; // P o r t o f o l i o a t t=0
Po r tof ( 1 ) == c t ( 1 ) // R e pli c a ti n g p o r t o f o l i o
f o r i =2:N+1
s=S t ( i ) ; Ttau ( i ) ;
// This makes the d i f f e r e n c e : Po r tof ( i ) == c t ( i )
Po r tof ( i ) = N1 t ( i −1)* s + p s i ( i −1)*B( i ) ;
// This makes the d i f f e r e n c e from
// Po r tof ( i ) = c t ( i ) ;
hedge ( i ) = ( N1 t ( i ) − N1 t ( i −1))* s ;
p s i ( i ) = ( c t ( i ) − N1 t ( i )* s )/B( i ) ;
( N1 t ( i −1)* s + p s i ( i −1)*B( i ) ) − ( N1 t ( i )* s + p s i ( i )*B( i ) ) ,
// Should be z e ro
end
// Check o b l i g a t i o n s
// Po r tof (N+1)−( S t (N+1)−K) ,
c t (N+1)−( S t (N+1)−K) ,
i f S t (N+1) > K
// i n the money
pay2buyer = S t (N+1)−K;
e l s e
// out of money
pay2buyer = 0 ;
end
// Do we have enough money?
// In ca s e ” out of money ” , we need Po r tof (N+1)=0
MymoneyLeft = Po r tof (N+1) − pay2buyer
/////////////////////////////////////////////////////////////////
// Avoid l o o p s i n s c i l a b : u se ma t rix al g e b r a i n s t e a d
/////////////////////////////////////////////////////////////////
Phi = N1 t ;
P si = ( c t−N1 t . * S t ) . /B;
Hedge = [ hedge ( 1 ) ; ( N1 t ( 2 :N+1) −
N1 t ( 1 :N) ) . * S t ( 2 :N+ 1 )];
// O P o r t of o l i o
PortoF = Phi . * S t + P si . *B;
// deve s e r r e p l i c a n t e
mabs ( PortoF − c t ) , // Has to be z e ro
i f S t (N+1) > K
// i n the money
pay2buyer = S t (N+1)−K
// Do we have enough money?
MymoneyLeft = PortoF (N+1) − pay2buyer
e l s e
// out of the money
pay2buyer = 0
// Do we have enough money?
MymoneyLeft = PortoF (N+1) − pay2buyer
end
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
nn =[1:N+ 1] ’;
pl o t ( nn , S t , ’ b−’ ,nn ,K* one s (N+1 ,1 ) , ’ b : ’ , nn , Hedge , ’ r ’ , nn , Psi , nn , Porto
x l a b e l ( ’ t r a di n g days ’ ) ;
y l a b e l ( ’ S ,K, Del ta S , Borrowed , Po r toFolio ’ ) ;
l eg e n d ( ’ S tock S ’ , ’ S t r i k e K’ , ’ Hedge=Del ta S ’ , ’ Borrowed ’ , ’ P o r t of o l i o ’ )//////////////////////////////////////////////////////////////////////
// Put
////////////////////////////////////////////////////////////////////
[ p t , n1 , n2]= V a nill a ( S t ,K, r , si g , Ttau , −1 );
phi = n1 t ;
p s i = ( p t−n1 t . * S t ) . /B;
Hedge = [ n1 (1 ) * S0 ; ( n1 t ( 2 :N+1)−n1 t ( 1 :N) ) . * S t ( 2 :N+ 1 )];
PortoF = phi . * S t + p s i . *B;
mabs ( PortoF − p t )
i f S t (N+1) < K
// i n the money
pay2buyer = K−S t (N+1) ,
// Do we have enough money?
MymoneyLeft = PortoF (N+1) − pay2buyer ,
e l s e
// out of the money
pay2buyer = 0
// Do we have enough money?
MymoneyLeft = PortoF (N+1) − pay2buyer ,
end