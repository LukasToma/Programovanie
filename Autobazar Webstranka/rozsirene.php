<?php
########################################
### include suboru pre pripojenie do DB
########################################
include ('connect.php');
?>
<!doctype html>
<html>
<head>
	<html lang="sk-SK">
	<meta charset='UTF-8'>
	<title>Autobazár</title>
	<meta name="copyright" content="Autobazár">
	<meta name="description" content="Autobazár">
	<meta name="keywords" content="autobazar,bazar,slovensko,cesko,auto,kupim,predam">
	<link rel="stylesheet" type="text/css" href="index.css">
		<!--fonty-->
		<link href="https://fonts.googleapis.com/css?family=Lato:100,300,400,700,900" rel="stylesheet">
		<link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.css" rel="stylesheet"/>

</head>
<body>
 
<div class="header">

<div class="topnav">
    <span class='logo'><img src="Web/abcauto_logo5.png" alt="ABC Auto logo"></span>
    <a href='index.php'>Vyhľadaj inzeráty</a>
	<a href='inzeraty.php'>Všetky inzeráty</a>
	<a href='kontakt.php'>Kontakt</a>

</div>	
</div>



<form action = "rozsirene-vysledky.php" method="POST">
<h2>Vyhľadaj inzeráty podľa kategórií:</h2>

<div class="center-form">
<div class="select-input1">
<!--  Znacka -->
<!--<label>Znacka:</label>-->
<select name='Znacka' id='Znacka' select class="select select1">
<option value='vsetko'>Značka</option>
		<option value='Ine'>Iné</option>
		<option value='Alfa Romeo'>Alfa Romeo</option>
		<option value='Aston Martin'>Aston Martin</option>
		<option value='Audi'>Audi</option>
		<option value='Bentley'>Bentley</option>
		<option value='BMW'>BMW</option>
		<option value='Citroen'>Citroen</option>
		<option value='Dacia'>Dacia</option>
		<option value='DS'>DS</option>
		<option value='Ferrari'>Ferrari</option>
		<option value='Fiat'>Fiat</option>
		<option value='Ford'>Ford</option>
		<option value='Honda'>Honda</option>
		<option value='Hyundai'>Hyundai</option>
		<option value='Jaguar'>Jaguar</option>
		<option value='Jeep'>Jeep</option>
		<option value='KIA'>KIA</option>
		<option value='Lamborghini'>Lamborghini</option>
		<option value='LandRover'>Land Rover</option>
		<option value='Lexus'>Lexus</option>
		<option value='Mazda'>Mazda</option>
		<option value='Mercedes'>Mercedes</option>
		<option value='Mini'>Mini</option>
		<option value='Mitsubishi'>Mitsubishi</option>
		<option value='Nissan'>Nissan</option>
		<option value='Opel'>Opel</option>
		<option value='Peugeot'>Peugeot</option>
		<option value='Porsche'>Porsche</option>
		<option value='Renault'>Renault</option>
		<option value='Rolls Royce'>Rolls-Royce</option>
		<option value='Seat'>Seat</option>
		<option value='Skoda'>Škoda</option>
		<option value='Smart'>Smart</option>
		<option value='Subaru'>Subaru</option>
		<option value='Suzuki'>Suzuki</option>
		<option value='Tesla'>Tesla</option>
		<option value='Toyota'>Toyota</option>
		<option value='Volkswagen'>Volkswagen</option>
		<option value='Volvo'>Volvo</option>
	</select>
	
</select>
<br>
</div>

<div class="text-input">
<!-- Model -->
<!--<label for='Model'>Model:</label>-->
<input name='Model' id='Model' type='text' placeholder='Vyhľadať model auta' value='' pattern="^[a-zA-Z0-9 ]*$"/>
<br>
</div>

<div class="select-input2">
<!-- CenaOd -->
<!--<label>Cena od:</label>-->
<select name='CenaOd' id='CenaOd' select class="select select2">
<option value='0'>Cena od:</option>
			<option value='500'>od 500 €</option>
			<option value='1000'>od 1 000 €</option>
			<option value='2000'>od 2 000 €</option>
			<option value='3000'>od 3 000 €</option>
			<option value='4000'>od 4 000 €</option>
			<option value='5000'>od 5 000 €</option>
			<option value='6000'>od 6 000 €</option>
			<option value='7000'>od 7 000 €</option>
			<option value='8000'>od 8 000 €</option>
			<option value='9000'>od 9 000 €</option>
			<option value='10000'>od 10 000 €</option>
			<option value='11000'>od 11 000 €</option>
			<option value='12000'>od 12 000 €</option>
			<option value='13000'>od 13 000 €</option>
			<option value='14000'>od 14 000 €</option>
			<option value='15000'>od 15 000 €</option>
			<option value='17500'>od 17 500 €</option>
			<option value='20000'>od 20 000 €</option>
			<option value='22500'>od 22 500 €</option>
			<option value='25000'>od 25 000 €</option>
			<option value='27500'>od 27 500 €</option>
			<option value='30000'>od 30 000 €</option>
			<option value='35000'>od 35 000 €</option>
			<option value='40000'>od 40 000 €</option>
			<option value='45000'>od 45 000 €</option>
			<option value='50000'>od 50 000 €</option>
			<option value='55000'>od 55 000 €</option>
			<option value='60000'>od 60 000 €</option>
			<option value='70000'>od 70 000 €</option>
			<option value='80000'>od 80 000 €</option>
			<option value='90000'>od 90 000 €</option>
			<option value='100000'>od 100 000 €</option>
	</select>

<!-- //CenaDo	-->
<!--<label>Cena do:</label>-->
<select name='CenaDo' id='CenaDo' select class="select select2">
<option value='9999999'>Cena do:</option>
			<option value='500'>do 500 €</option>
			<option value='1000'>do 1 000 €</option>
			<option value='2000'>do 2 000 €</option>
			<option value='3000'>do 3 000 €</option>
			<option value='4000'>do 4 000 €</option>
			<option value='5000'>do 5 000 €</option>
			<option value='6000'>do 6 000 €</option>
			<option value='7000'>do 7 000 €</option>
			<option value='8000'>do 8 000 €</option>
			<option value='9000'>do 9 000 €</option>
			<option value='10000'>do 10 000 €</option>
			<option value='11000'>do 11 000 €</option>
			<option value='12000'>do 12 000 €</option>
			<option value='13000'>do 13 000 €</option>
			<option value='14000'>do 14 000 €</option>
			<option value='15000'>do 15 000 €</option>
			<option value='17500'>do 17 500 €</option>
			<option value='20000'>do 20 000 €</option>
			<option value='22500'>do 22 500 €</option>
			<option value='25000'>do 25 000 €</option>
			<option value='27500'>do 27 500 €</option>
			<option value='30000'>do 30 000 €</option>
			<option value='35000'>do 35 000 €</option>
			<option value='40000'>do 40 000 €</option>
			<option value='45000'>do 45 000 €</option>
			<option value='50000'>do 50 000 €</option>
			<option value='55000'>do 55 000 €</option>
			<option value='60000'>do 60 000 €</option>
			<option value='70000'>do 70 000 €</option>
			<option value='80000'>do 80 000 €</option>
			<option value='90000'>do 90 000 €</option>
			<option value='100000'>do 100 000 €</option>
	</select>
<br>
</div>

<div class="select-input2">
<!-- //RokOd	-->
<!--<label>Rok od:</label>-->
<select name='RokOd' id='RokOd' select class="select select2">
<option value='0'>Rok výroby od:</option>
			<option value='2022'>od 2022</option>
			<option value='2021'>od 2021</option>
			<option value='2020'>od 2020</option>
			<option value='2019'>od 2019</option>
			<option value='2018'>od 2018</option>
			<option value='2017'>od 2017</option>
			<option value='2016'>od 2016</option>
			<option value='2015'>od 2015</option>
			<option value='2014'>od 2014</option>
			<option value='2013'>od 2013</option>
			<option value='2012'>od 2012</option>
			<option value='2011'>od 2011</option>
			<option value='2010'>od 2010</option>
			<option value='2009'>od 2009</option>
			<option value='2008'>od 2008</option>
			<option value='2007'>od 2007</option>
			<option value='2006'>od 2006</option>
			<option value='2005'>od 2005</option>
			<option value='2004'>od 2004</option>
			<option value='2003'>od 2003</option>
			<option value='2002'>od 2002</option>
			<option value='2001'>od 2001</option>
			<option value='2000'>od 2000</option>
			<option value='1995'>od 1995</option>
			<option value='1990'>od 1990</option>
			<option value='1985'>od 1985</option>
			<option value='1980'>od 1980</option>
			<option value='1975'>od 1975</option>
			<option value='1970'>od 1970</option>
			<option value='0'>do 1970</option>
	</select>

<!-- //RokDo -->
<!--<label>Rok do:</label>-->
<select name='RokDo' id='RokDo' select class="select select2">
<option value='9999'>Rok výroby do:</option>
			<option value='2022'>do 2022</option>
			<option value='2021'>do 2021</option>
			<option value='2020'>do 2020</option>
			<option value='2019'>do 2019</option>
			<option value='2018'>do 2018</option>
			<option value='2017'>do 2017</option>
			<option value='2016'>do 2016</option>
			<option value='2015'>do 2015</option>
			<option value='2014'>do 2014</option>
			<option value='2013'>do 2013</option>
			<option value='2012'>do 2012</option>
			<option value='2011'>do 2011</option>
			<option value='2010'>do 2010</option>
			<option value='2009'>do 2009</option>
			<option value='2008'>do 2008</option>
			<option value='2007'>do 2007</option>
			<option value='2006'>do 2006</option>
			<option value='2005'>do 2005</option>
			<option value='2004'>do 2004</option>
			<option value='2003'>do 2003</option>
			<option value='2002'>do 2002</option>
			<option value='2001'>do 2001</option>
			<option value='2000'>do 2000</option>
			<option value='1995'>do 1995</option>
			<option value='1990'>do 1990</option>
			<option value='1985'>do 1985</option>
			<option value='1980'>do 1980</option>
			<option value='1975'>do 1975</option>
			<option value='1970'>do 1970</option>
	</select>		
<br>
</div>

<div class="select-input2">
<!-- //NajazdOd -->

<select name='NajazdOd' id='NajazdOd' select class="select select2">
<option value='0'>Najazdené km od:</option>
			<option value='1000'>od 1 000 km</option>
			<option value='5000'>od 5 000 km</option>
			<option value='10000'>od 10 000 km</option>
			<option value='25000'>od 25 000 km</option>
			<option value='50000'>od 50 000 km</option>
			<option value='75000'>od 75 000 km</option>
			<option value='100000'>od 100 000 km</option>
			<option value='125000'>od 125 000 km</option>
			<option value='150000'>od 150 000 km</option>
			<option value='175000'>od 175 000 km</option>
			<option value='200000'>od 200 000 km</option>
			<option value='225000'>od 225 000 km</option>
			<option value='250000'>od 250 000 km</option>
			<option value='300000'>od 300 000 km</option>
			<option value='400000'>od 400 000 km</option>
			<option value='500000'>od 500 000 km</option>
	</select>             

<!-- //NajazdDo -->

<select name='NajazdDo' id='NajazdDo' select class="select select2">
<option value='9999999'>Najazdené km do:</option>
			<option value='1000'>do 1000 km</option>
			<option value='5000'>do 5000 km</option>
			<option value='10000'>do 10 000 km</option>
			<option value='25000'>do 25 000 km</option>
			<option value='50000'>do 50 000 km</option>
			<option value='75000'>do 75 000 km</option>
			<option value='100000'>do 100 000 km</option>
			<option value='125000'>do 125 000 km</option>
			<option value='150000'>do 150 000 km</option>
			<option value='175000'>do 175 000 km</option>
			<option value='200000'>do 200 000 km</option>
			<option value='225000'>do 225 000 km</option>
			<option value='250000'>do 250 000 km</option>
			<option value='300000'>do 300 000 km</option>
			<option value='400000'>do 400 000 km</option>
			<option value='500000'>do 500 000 km</option>
	</select>		
<br>
</div>

<button type="button"  onclick="location.href='index.php'" button class="button button5">Základné vyhľadávanie</button>
<h4>Rozšírené vyhľadávanie:</h4>


<div class="select-input2">	
<!-- //VykonOd -->

<select name='VykonOd' id='VykonOd' select class="select select2">
<option value='0'>Výkon od:</option>
			<option value='50'>od 50 koní</option>
			<option value='75'>od 75 koní</option>
			<option value='100'>od 100 koní</option>
			<option value='125'>od 125 koní</option>
			<option value='150'>od 150 koní</option>
			<option value='175'>od 175 koní</option>
			<option value='200'>od 200 koní</option>
			<option value='250'>od 250 koní</option>
			<option value='300'>od 300 koní</option>
			<option value='400'>od 400 koní</option>
			<option value='500'>od 500 koní</option>
	</select>	 
<!--
</div>


<div class="select-input">
-->
<!-- //VykonDo -->

<select name='VykonDo' id='VykonDo' select class="select select2">
<option value='9999'>Výkon do:</option>
			<option value='50'>do 50 koní</option>
			<option value='75'>do 75 koní</option>
			<option value='100'>do 100 koní</option>
			<option value='125'>do 125 koní</option>
			<option value='150'>do 150 koní</option>
			<option value='175'>do 175 koní</option>
			<option value='200'>do 200 koní</option>
			<option value='250'>do 250 koní</option>
			<option value='300'>do 300 koní</option>
			<option value='400'>do 400 koní</option>
			<option value='500'>do 500 koní</option>
	</select>	 
<br>
</div>

<div class="select-input1">
<!--//Palivo -->

<select name='Palivo' id='Palivo' select class="select select1">
<option value='%'>Typ paliva:</option>
		<option value='Benzin'>Benzín</option>
		<option value='Diesel'>Diesel</option>
		<option value='Hybrid'>Hybrid</option>
		<option value='Elektro'>Elektromobil</option>
		<option value='Plyn'>Plyn+Benzín</option>
	</select>
<br>
</div>

<div class="select-input1">
<!-- //Prevodovka -->

<select name='Prevodovka' id='Prevodovka' select class="select select1">
<option value='%'>Typ prevodovky:</option>
		<option value='Automaticka'>Automatická prevodovka</option>
		<option value='Manualna'>Manuálna prevodovka</option>
	</select>
<br>
</div>

<div class="text-input">
<!-- Vybava -->
<!--<label for='Vybava>Vybava:</label>-->
<input name='Vybava' id='Vybava' type='text' placeholder='Vyhľadať výbavu' value='' pattern="^[a-zA-Z0-9 ]*$"/>
<br>
</div>

<fieldset>
  <legend>Zvoliť výbavu:</legend>
     <div>
    <input type="checkbox" id="Klimatizacia" name="Vybava1" value="Klimatizacia">
    <label for="Klimatizacia">Klimatizácia</label>
  </div>
  <div>
    <input type="checkbox" id="Elektricke okna 4x" name="Vybava2" value="Elektricke okna 4x">
    <label for="Elektricke okna 4x">Elektrické okná 4x</label>
  </div>
    <div>
    <input type="checkbox" id="Tempomat" name="Vybava3" value="Tempomat">
    <label for="Tempomat">Tempomat</label>
  </div>
    <div>
    <input type="checkbox" id="Parkovacie senzory" name="Vybava4" value="Parkovacie senzory">
    <label for="Parkovacie senzory">Parkovacie senzory</label>
  </div>
    <div>
    <input type="checkbox" id="Kozeny interier" name="Vybava5" value="Kozen">
    <label for="Kozeny interier">Kožený interiér</label>
  </div>
    <div>
    <input type="checkbox" id="Stresne okno" name="Vybava6" value="Stresne okno">
    <label for="Stresne okno">Strešné okno</label>
  </div>
    <div>
    <input type="checkbox" id="Navigacia" name="Vybava7" value="Navigac">
    <label for="Navigacia">Navigácia</label>
  </div>
  <div>
    <input type="checkbox" id="Welcome light" name="Vybava8" value="Welcome light" class="red">
    <label for="Welcome light"><span>Welcome light</span></label>
  </div>
  
</fieldset>
	
		
<div class="buttons">
		<input type="submit" button class="button button1" value='Hľadať'>
		<input type="reset"  button class="button button2" value='Resetovať'>
</div>
</div>

</form>
</body>
</html>