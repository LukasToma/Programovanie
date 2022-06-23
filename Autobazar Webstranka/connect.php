<?php 
# Idem vytvorit subor pre spojenie s DB

$sql_server = "localhost"; // nazov SQL servera IP adresa/localhost
$sql_user = "autobazar"; //nazov uzivatela
$sql_pass = "autobazar"; //heslo pre uzivatela
$sql_db = "autobazar"; //databaza s ktorou chcem pracovat

$sql_con = new mysqli($sql_server, $sql_user, $sql_pass, $sql_db);

$result = $sql_con->query("SET NAMES 'utf8'");


if ($sql_con->connect_error)
{
	die("Nastala chyba spojenia ...!".$sql_con->connect_error);
}
else
	//echo "OK";
	
?>