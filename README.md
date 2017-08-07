## Utility to Calculate Qpen from Mixed Layer Depth, Chlorophyll and shortwave

### Installation

##### Become root user
```
[akshay@localhost tmp]$ su 
Password: 
```
##### Extract compressed file
```
[root@localhost tmp]# unzip Qpen-From-MLD-CHL-and-Shortwave-master.zip
README.md
qpen_from_mld_chl_shortwave/ 
qpen_from_mld_chl_shortwave/Makefile 
qpen_from_mld_chl_shortwave/qpen_from_mld_chl_shortwave_debug.c 
qpen_from_mld_chl_shortwave/README 
```

##### Go to qpen_from_mld_chl_shortwave directory

```
[root@localhost tmp]# cd qpen_from_mld_chl_shortwave
```

##### Compile & install

```
[root@localhost qpen_from_mld_chl_shortwave]# make 
[root@localhost qpen_from_mld_chl_shortwave]# make install 
```

##### Version

```
[root@localhost qpen_from_mld_chl_shortwave]# qpen_from_mld_chl_shortwave --version
Rev 1.0.0 (Thu Jun 11 16:41:38 UTC 2015)
```

##### Help

```
[root@localhost qpen_from_mld_chl_shortwave]# qpen_from_mld_chl_shortwave --help

Usage               
                qpen_from_mld_chl_shortwave [OPTIONS]

Arguments 

                -m --mld Mixed Layer Depth in Meter
                -c --chl Chlorophyll mg m^-3
                -s --shortwave Pressure in w/m^2
                -v --version Show program version
                -h --help Show help


Examples :
	 qpen_from_mld_chl_shortwave   --mld=6.69425 --chl=0.19175 --shortwave=238.4
	 46.1120550163

	 OR

	 qpen_from_mld_chl_shortwave   -m 6.69425 -c 0.19175 -s 238.4
	 46.1120550163

         If you find any bugs report to ahegde@nio.org / akshay.k.hegde@gmail.com
``` 

### Usage

##### Usage with long options

```
[root@localhost qpen_from_mld_chl_shortwave]# qpen_from_mld_chl_shortwave   --mld=6.69425 --chl=0.19175 --shortwave=238.4
46.1120550163
``` 

##### Usage with short options

```
[root@localhost qpen_from_mld_chl_shortwave]# qpen_from_mld_chl_shortwave   -m 6.69425 -c 0.19175 -s 238.4
46.1120550163
```

##### Calculation using file

```
[akshay@localhost tmp]$ cat file.txt 
MLD	CHL	Shortwave
6.69425	0.191750	238.4
9.28058	0.189056	227.8
14.2633	0.186362	237.6
17.9191	0.183669	211
13.3187	0.180975	230.7
12.9831	0.178281	252.4
``` 

##### Write simple bash script something like this

```
[akshay@localhost tmp]$ cat run.sh 
#!/usr/bin/env bash 
i=0 
while read mld chl shortwave; do 
	[ $i -eq 0 ] && qpen="Qpen" || qpen=$(qpen_from_mld_chl_shortwave --mld=$mld --chl=$chl --shortwave=$shortwave) 
	echo "$mld $chl $shortwave $qpen" 
i=$((i+1)) 
done < file.txt
``` 

##### Execute

```
[akshay@localhost tmp]$ bash run.sh 
MLD CHL Shortwave Qpen
6.69425 0.191750 238.4 46.1120550163
9.28058 0.189056 227.8 36.8895559902
14.2633 0.186362 237.6 27.7617404501
17.9191 0.183669 211 19.5095716149
13.3187 0.180975 230.7 28.9050220167
12.9831 0.178281 252.4 32.4441108666
``` 


