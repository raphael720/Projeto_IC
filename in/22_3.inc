sets	
	j siparis turu   /1*30/
	k knapsack indisi /1*3/
	r kalip indisi /1*3/;
alias(i,j);	
*buyuk pozitif sayi	
scalar U/30/; 	
*kapasite harcama miktarlari	
parameter w(j)/	
1	41
2	35
3	44
4	15
5	45
6	25
7	33
8	37
9	18
10	45
11	16
12	20
13	44
14	9
22	28
23	5
24	35
25	44
26	15
27	15
28	47
29	40
30	39
/;	
parameter cap(k);	
cap(k)=211;	
	
*orjinal p degerleri	
parameter po(j)/	
1	0
2	0
3	0
4	0
5	0
6	0
7	0
8	0
9	266
10	0
11	0
12	0
13	0
14	0
15	0
16	0
17	166
18	12
19	251
20	0
21	0
22	0
23	0
24	0
25	426
26	368
27	0
28	0
29	0
30	334
/ ;	
parameter pp(i,j)/	
1.2=19	
1.3=0	
1.4=0	
1.5=0	
1.6=0	
1.7=0	
1.8=0	
1.9=0	
1.10=6	
1.11=0	
1.12=0	
1.13=0	
1.14=4	
1.15=0	
1.16=0	
1.17=3	
1.18=9	
1.19=0	
1.20=1	
1.21=0	
1.22=0	
1.23=0	
1.24=15	
1.25=0	
1.26=0	
1.27=14	
1.28=0	
1.29=0	
1.30=13	
2.3=0	
2.4=0	
2.5=12	
2.6=0	
2.7=0	
2.8=17	
2.9=0	
2.10=0	
2.11=0	
2.12=0	
2.13=0	
2.14=0	
2.15=0	
2.16=14	
2.17=2	
2.18=16	
2.19=0	
2.20=15	
2.21=0	
2.22=2	
2.23=0	
2.24=0	
2.25=0	
2.26=10	
2.27=0	
2.28=0	
2.29=0	
2.30=0	
3.4=0	
3.5=0	
3.6=0	
3.7=4	
3.8=0	
3.9=0	
3.10=0	
3.11=0	
3.12=0	
3.13=9	
3.14=0	
3.15=0	
3.16=0	
3.17=0	
3.18=0	
3.19=0	
3.20=0	
3.21=10	
3.22=0	
3.23=0	
3.24=4	
3.25=0	
3.26=12	
3.27=0	
3.28=10	
3.29=0	
3.30=0	
4.5=0	
4.6=0	
4.7=0	
4.8=0	
4.9=0	
4.10=0	
4.11=8	
4.12=0	
4.13=0	
4.14=0	
4.15=0	
4.16=11	
4.17=0	
4.18=0	
4.19=10	
4.20=0	
4.21=0	
4.22=0	
4.23=12	
4.24=0	
4.25=0	
4.26=0	
4.27=0	
4.28=14	
4.29=0	
4.30=0	
5.6=0	
5.7=10	
5.8=0	
5.9=0	
5.10=0	
5.11=17	
5.12=0	
5.13=20	
5.14=0	
5.15=0	
5.16=0	
5.17=0	
5.18=0	
5.19=11	
5.20=0	
5.21=0	
5.22=0	
5.23=0	
5.24=0	
5.25=0	
5.26=17	
5.27=0	
5.28=0	
5.29=0	
5.30=0	
6.7=0	
6.8=0	
6.9=19	
6.10=0	
6.11=0	
6.12=0	
6.13=0	
6.14=0	
6.15=0	
6.16=0	
6.17=0	
6.18=0	
6.19=0	
6.20=1	
6.21=0	
6.22=17	
6.23=1	
6.24=0	
6.25=0	
6.26=0	
6.27=0	
6.28=0	
6.29=13	
6.30=0	
7.8=0	
7.9=0	
7.10=0	
7.11=0	
7.12=0	
7.13=0	
7.14=0	
7.15=0	
7.16=0	
7.17=0	
7.18=0	
7.19=0	
7.20=0	
7.21=0	
7.22=0	
7.23=10	
7.24=0	
7.25=0	
7.26=15	
7.27=0	
7.28=0	
7.29=12	
7.30=0	
8.9=12	
8.10=0	
8.11=0	
8.12=18	
8.13=18	
8.14=0	
8.15=0	
8.16=1	
8.17=0	
8.18=0	
8.19=0	
8.20=17	
8.21=0	
8.22=0	
8.23=0	
8.24=5	
8.25=3	
8.26=6	
8.27=0	
8.28=0	
8.29=0	
8.30=0	
9.10=0	
9.11=14	
9.12=0	
9.13=0	
9.14=0	
9.15=0	
9.16=0	
9.17=0	
9.18=0	
9.19=0	
9.20=0	
9.21=0	
9.22=15	
9.23=0	
9.24=0	
9.25=5	
9.26=0	
9.27=11	
9.28=0	
9.29=0	
9.30=0	
10.11=0	
10.12=4	
10.13=7	
10.14=3	
10.15=0	
10.16=0	
10.17=0	
10.18=0	
10.19=0	
10.20=7	
10.21=0	
10.22=0	
10.23=0	
10.24=0	
10.25=9	
10.26=0	
10.27=0	
10.28=14	
10.29=0	
10.30=5	
11.12=0	
11.13=0	
11.14=0	
11.15=0	
11.16=0	
11.17=0	
11.18=0	
11.19=0	
11.20=0	
11.21=0	
11.22=0	
11.23=0	
11.24=0	
11.25=0	
11.26=15	
11.27=0	
11.28=0	
11.29=0	
11.30=0	
12.13=9	
12.14=0	
12.15=0	
12.16=0	
12.17=0	
12.18=0	
12.19=0	
12.20=0	
12.21=6	
12.22=0	
12.23=0	
12.24=0	
12.25=0	
12.26=0	
12.27=0	
12.28=0	
12.29=2	
12.30=0	
13.14=0	
13.15=0	
13.16=0	
13.17=12	
13.18=0	
13.19=9	
13.20=3	
13.21=0	
13.22=0	
13.23=13	
13.24=0	
13.25=0	
13.26=0	
13.27=0	
13.28=0	
13.29=0	
13.30=0	
14.15=0	
14.16=0	
14.17=0	
14.18=0	
14.19=0	
14.20=0	
14.21=0	
14.22=10	
14.23=18	
14.24=0	
14.25=0	
14.26=0	
14.27=0	
14.28=7	
14.29=0	
14.30=0	
15.16=0	
15.17=0	
15.18=0	
15.19=9	
15.20=0	
15.21=0	
15.22=0	
15.23=0	
15.24=13	
15.25=0	
15.26=0	
15.27=20	
15.28=0	
15.29=0	
15.30=0	
16.17=0	
16.18=0	
16.19=0	
16.20=0	
16.21=0	
16.22=0	
16.23=0	
16.24=0	
16.25=0	
16.26=0	
16.27=0	
16.28=15	
16.29=6	
16.30=0	
17.18=16	
17.19=0	
17.20=0	
17.21=0	
17.22=0	
17.23=19	
17.24=0	
17.25=12	
17.26=9	
17.27=0	
17.28=0	
17.29=0	
17.30=0	
18.19=0	
18.20=0	
18.21=0	
18.22=0	
18.23=0	
18.24=2	
18.25=0	
18.26=20	
18.27=0	
18.28=0	
18.29=0	
18.30=0	
19.20=0	
19.21=0	
19.22=0	
19.23=0	
19.24=0	
19.25=0	
19.26=7	
19.27=0	
19.28=0	
19.29=0	
19.30=0	
20.21=0	
20.22=6	
20.23=0	
20.24=0	
20.25=0	
20.26=0	
20.27=0	
20.28=0	
20.29=0	
20.30=5	
21.22=0	
21.23=2	
21.24=0	
21.25=16	
21.26=0	
21.27=0	
21.28=0	
21.29=0	
21.30=0	
22.23=0	
22.24=0	
22.25=11	
22.26=3	
22.27=16	
22.28=17	
22.29=9	
22.30=5	
23.24=0	
23.25=0	
23.26=0	
23.27=0	
23.28=18	
23.29=0	
23.30=0	
24.25=0	
24.26=0	
24.27=0	
24.28=0	
24.29=0	
24.30=12	
25.26=9	
25.27=0	
25.28=13	
25.29=8	
25.30=0	
26.27=0	
26.28=0	
26.29=0	
26.30=0	
27.28=0	
27.29=0	
27.30=0	
28.29=7	
28.30=0	
29.30=0	
/;	
parameter t(r,j)/	
1.1=1	
2.2=1	
3.3=1	
1.4=1	
1.5=1	
1.6=1	
1.7=1	
1.8=1	
1.9=1	
1.10=1	
1.11=1	
1.12=1	
1.13=1	
1.14=1	
1.15=1	
1.16=1	
1.17=1	
1.18=1	
1.19=1	
1.20=1	
1.21=1	
1.22=1	
1.23=1	
1.24=1	
1.25=1	
1.26=1	
1.27=1	
1.28=1	
1.29=1	
1.30=1	
/;	
parameter s(r)/	
1	12
2	14
3	15
/;	
parameter nr(r)/	
1	1
2	1
3	1
/;	
parameter psi(r,k)/	
1.1=0.11	
1.2=0	
1.3=0.83	
2.1=0.42	
2.2=0	
2.3=0.99	
3.1=0.03	
3.2=0.35	
3.3=0	
/;	
parameter sigma(r,k)/	
1.1=1	
1.2=0	
1.3=1	
2.1=1	
2.2=0	
2.3=1	
3.1=1	
3.2=1	
3.3=0	
/;	
parameter p(j,k);	
p(j,k)=po(j)*sum(r,t(r,j)*psi(r,k));	
parameter epsilon(j,k);	
epsilon(j,k)=sum(r,t(r,j)*sigma(r,k)); 	
