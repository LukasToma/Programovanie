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
	<link href="dist/css/lightbox.css" rel="stylesheet" />
	<!--fonty-->
	<link href="https://fonts.googleapis.com/css?family=Lato:100,300,400,700,900" rel="stylesheet">
</head>

<div class="header">
	<div class="topnav">
		<span class='logo'><img src="Web/abcauto_logo5.png" alt="ABC Auto logo"></span>
		<a href='index.php'>Vyhľadaj inzeráty</a>
		<a href='inzeraty.php'>Všetky inzeráty</a>
		<a href='kontakt.php'>Kontakt</a>
	</div>	
</div>

<body>
<h2>Bližšie informácie o aute: </h2>

<!--<div class="car-center">-->

<?php
$sql = "SELECT *\n"

    . "FROM `autobazar`.`inzeraty`\n"

    . "WHERE InzeratyID='$_GET[InzeratyID]';";	
	

$sql1 = "SELECT *\n"

    . "FROM `autobazar`.`inzeraty` \n"

    . "INNER JOIN `galeria` \n"

    . "ON `inzeraty`.`InzeratyID` = `galeria`.`IDinzeraty`\n"
	. "WHERE InzeratyID='$_GET[InzeratyID]';";			
	

$vysledok = mysqli_query($sql_con,$sql);
$zaznam = mysqli_fetch_assoc($vysledok);


echo "<div class='car-center'>";


echo "<div class='car-picture'>";

echo '<a href="data:image/jpeg; base64,'.base64_encode($zaznam['Obrazok']).'"
 data-lightbox="fotogaleria" data-title="Kliknite na pravú stranu obrázka alebo použite šípky pre pokračovanie v galérií."><img src="data:image/jpeg; base64,'.base64_encode($zaznam['Obrazok']).'"
 width="640" height="480"/></a>';

echo "</div>";
echo "<br />";

echo "<div class='car-text'>";

echo "<span class='center'>";
if ("Ine"!=($zaznam['Znacka'])) {
	echo "<strong>$zaznam[Znacka] </strong>"; 
echo "$zaznam[Model]"; }
	else {
		echo "<strong>$zaznam[Model]</strong>";
	}


echo "</span>";	
echo "<br />";
echo "<br />";

echo "<span class='left'><strong><label>Rok výroby: </label></strong></span>";
echo "<span class='right'>$zaznam[Rok]</span>";
echo "<br />";

echo "<span class='left'><strong><label>Cena: </label></strong></span>";

echo "<span class='right'>$zaznam[Cena] €</span>";

echo "<br />";

echo "<span class='left'><strong><label>Najazdené kilometre: </label></strong></span>";
echo "<span class='right'>$zaznam[Najazd] km</span>";
echo "<br />";

echo "<span class='left'><strong><label>Výkon: </label></strong></span>";
$kW="0.7355"*$zaznam['Vykon'];
$kW=intval(round($kW));
echo "<span class='right'>$kW kW/$zaznam[Vykon] koní</span>";
echo "<br />";

echo "<span class='left'><strong><label>Typ paliva: </label></strong></span>";
echo "<span class='right'>$zaznam[Palivo]</span>";
echo "<br />";

echo "<span class='left'><strong><label>Typ prevodovky: </label></strong></span>";
echo "<span class='right'>$zaznam[Prevodovka] prevodovka</span>";
echo "<br />";

//podmienka ci sa nachadza popis, ak nie tak skryje label popisu
if (!empty($zaznam['Popis'])) {
	echo "<p>";
	echo "<strong><label>Popis: </label></strong>";
	echo "</p>";
	echo "<p>";
	echo nl2br(htmlspecialchars("$zaznam[Popis]"));
	echo "</p>";
}

echo "</div>";
echo "</div>";

$vysledok1 = mysqli_query($sql_con,$sql1);
$zaznam1 = mysqli_fetch_assoc($vysledok1);

//podmienka ci sa tam nejaka fotka nachadza, ak nie tak skryje label fotogalerie
for ($i = 2; $i <= 10; $i++) {
if ((!empty($zaznam1["obrazok$i"]))) {
echo "<div class='image-gallery'>";
echo "<p>";
echo "<strong><label>Fotogaléria: </label></strong>";
echo "</p>";
break;
}
}

//podmienka pre vypisanie obrazkov vo fotogalerii
for ($i = 2; $i <= 10; $i++) {
if (!empty($zaznam1["obrazok$i"])) {
echo '<a href="data:image/jpeg; base64,'.base64_encode($zaznam1["obrazok$i"]).'"
 data-lightbox="fotogaleria" data-title="Kliknite na pravú stranu obrázka alebo použite šípky pre pokračovanie v galérií."><img src="data:image/jpeg; base64,'.base64_encode($zaznam1["obrazok$i"]).'"
 width="160" height="120"/></a>';
}
}

echo "</div>";
echo "<br />";


?>

<script src="dist/js/lightbox-plus-jquery.js"></script>
</body>
</html>