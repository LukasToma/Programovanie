<?php
########################################
### include suboru pre pripojenie do DB
########################################
include ('connect.php');
?>
<!DOCTYPE HTML>
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
</head>
<body>
<div class="header">

<div class="topnav">
    <span class='logo'><img src="Web/abcauto_logo5.png" alt="ABC Auto logo"></span>
	<a href='index.php'>Vyhľadaj inzeráty</a>
	<a href='inzeraty.php'>Pozri všetky inzeráty</a>
	<a href='kontakt.php'>Kontakt</a>
</div>	

</div>
	
	<h2>Vybrané inzeráty:</h2>
	

	
<?php
########################################
### zistim zoznam vsetkych inzeratov
########################################

//podmienka aby nevyhadzovalo error ze nevie co je model
if($_POST['Model']==""){
	$_POST['Model']="%";
}

//podmienka aby nevyhadzovalo error ze nevie co je vybava2
for ($i = 1; $i <= 8; $i++) {
if ((empty($_POST["Vybava$i"]))) {
	$_POST["Vybava$i"]="%";
}
}

if($_POST['Znacka']  == "vsetko"){

$sql = "SELECT * FROM `autobazar`.`inzeraty`\n"

    . "WHERE 	
				(Cena BETWEEN '$_POST[CenaOd]' AND '$_POST[CenaDo]') AND
				(Model LIKE '%$_POST[Model]%') AND
				(Rok BETWEEN '$_POST[RokOd]' AND '$_POST[RokDo]') AND 
				(Najazd BETWEEN '$_POST[NajazdOd]' AND '$_POST[NajazdDo]') AND
				(Vykon BETWEEN '$_POST[VykonOd]' AND '$_POST[VykonDo]') AND
				(Palivo LIKE '$_POST[Palivo]') AND
				(Prevodovka LIKE '$_POST[Prevodovka]') AND
				(Popis LIKE '%$_POST[Vybava]%') AND
				(Popis LIKE '%$_POST[Vybava1]%') AND
				(Popis LIKE '%$_POST[Vybava2]%') AND
				(Popis LIKE '%$_POST[Vybava3]%') AND
				(Popis LIKE '%$_POST[Vybava4]%') AND
				(Popis LIKE '%$_POST[Vybava5]%') AND
				(Popis LIKE '%$_POST[Vybava6]%') AND
				(Popis LIKE '%$_POST[Vybava7]%') AND
				(Popis LIKE '%$_POST[Vybava8]%')"
				. "ORDER BY `Cena` ASC;";
}else{
		$sql = "SELECT * FROM `autobazar`.`inzeraty`\n"

				. "WHERE 	(Znacka = '$_POST[Znacka]') AND
				(Model LIKE '%$_POST[Model]%') AND
				(Cena BETWEEN '$_POST[CenaOd]' AND '$_POST[CenaDo]') AND
				(Rok BETWEEN '$_POST[RokOd]' AND '$_POST[RokDo]') AND 
				(Najazd BETWEEN '$_POST[NajazdOd]' AND '$_POST[NajazdDo]') AND
				(Vykon BETWEEN '$_POST[VykonOd]' AND '$_POST[VykonDo]') AND 
				(Palivo LIKE '$_POST[Palivo]') AND
				(Prevodovka LIKE '$_POST[Prevodovka]') AND
				(Popis LIKE '%$_POST[Vybava]%') AND
				(Popis LIKE '%$_POST[Vybava1]%') AND
				(Popis LIKE '%$_POST[Vybava2]%') AND
				(Popis LIKE '%$_POST[Vybava3]%') AND
				(Popis LIKE '%$_POST[Vybava4]%') AND
				(Popis LIKE '%$_POST[Vybava5]%') AND
			    (Popis LIKE '%$_POST[Vybava6]%') AND
				(Popis LIKE '%$_POST[Vybava7]%') AND
				(Popis LIKE '%$_POST[Vybava8]%')"
				. "ORDER BY `Cena` ASC;";
				
} 

 
echo "<div class='table-header'>";
echo "<table>";
$vysledok = mysqli_query($sql_con,$sql);	// vysledok dotazu
	
        echo "<table border='1' style='border-collapse:collapse'>";
        echo "<tr>";
		echo "<th>Auto</th>";
		echo "<th>Cena</th>";
		echo "<th>Rok</th>";
		echo "<th>Najazdené km</th>";		
		echo "<th>Výkon</th>";		
		echo "<th>Palivo</th>";
		echo "<th>Prevodovka</th>";
		echo "<th>Obrázok</th>";
		echo "<th>Link na otvorenie inzerátu</th>";
		echo "</tr>";

// vysledok nacitam do zaznamov po riadkoch
echo "</div>";

?>
<div class="table-content">
<?php


while ($zaznam = mysqli_fetch_assoc($vysledok)) //neobjektovy sposob
	{
		echo "<tr>";

		echo "<td>$zaznam[Znacka] $zaznam[Model]</td>";
		echo "<td>$zaznam[Cena] €</td>";
		echo "<td>$zaznam[Rok]</td>";
		echo "<td>$zaznam[Najazd] km</td>";
		echo "<td>$zaznam[Vykon] koní</td>";
		echo "<td>$zaznam[Palivo]</td>";
		echo "<td>$zaznam[Prevodovka]</td>";
		echo '<td><img src="data:image/jpeg; base64,'.base64_encode($zaznam['Obrazok']).'" width=300" height="225"/></td>';
		echo "<td><a href='auto.php?InzeratyID=$zaznam[InzeratyID]'>Pozri inzerát</a></td>";	   
		echo "</tr>";
	}

echo "</table>";
?>
</div>

<div class="button3-center">
<p>
<button onclick="location.href='rozsirene.php'" button class="button button3">Späť</button>
</p>
</div>
</body>