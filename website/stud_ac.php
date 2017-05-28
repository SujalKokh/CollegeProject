
<?php
session_start();

if(!$_SESSION['name'])
{
	header("location: index.php");
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
	<title> Rambhakta Memorial School </title>
	<meta charset="utf-8" />
	<link rel="stylesheet"  href="style.css" type="text/css"/> 
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>	
	<body background="backgroung.jpg">
	
		<div id="container">
		<div id="header">
		<img src="logoe.jpg" height="75" width="100%" alt="RMS_logo" align="center">
		</div> 
	
				<div id="navigation">
				
			<div id='cssmenu'>
<ul>
	<li><a href="index.php"><span>Home</span></a></li>
	<li><a href="Admission.php"><span>Admission</span></a>
   <li><a href="teacher.php"><span>Teachers</span></a></li>
   
   <li class='last'><a href="Token.php"><span>Tokens</span></a></li>
      <li class='active has-sub'><a href="admin.php"><span>MANAGE</span></a>
      <ul>
			 <li class='has-sub'><a href="admin.php"><span>Tokens</span></a></li>
         <li class='has-sub'><a href="teach_ac.php"><span>Teacher A/C</span></a></li>
         <li class='has-sub'><a href="stud_ac.php"><span>Student A/C</span></a></li>
		  <li class='has-sub'><a href="stud_ac.php"><span>Admin A/C</span></a></li>
      </ul>
   </li>
	<li class='last'><a href="logout.php"><span>LOG OUT</span></a></li>
</ul>
   

</ul>
</div>

	
<td width="1000">
		<table>
			<tr>
				
				<td width="150">
					<div class="left_bar">

					</div>
				</td>
				
				<td width="900">
					<div class="mid">
					<h1>Student account</h1>
						<p>

<strong>

  <span style="font-weight: bold;">
<font color="#535B68"><?php echo $_SESSION['name']; ?></font>
		<a href='logout.php'><input type="button" value="logout"/></a></font></font>

    </span>

</strong>




<?php
$con = mysql_connect("localhost","root","");
if(!$con){
die("Can not connect:" . mysql_error());
}

mysql_select_db("rms",$con);

// for add update and delete queries

if(isset($_POST['update'])){
$UpdateQuery ="UPDATE students Set id='$_POST[id]', Name='$_POST[name]',Token='$_POST[password]' WHERE id='$_POST[hidden]'";
mysql_query($UpdateQuery,$con);
};

if(isset($_POST['delete'])){
$DeleteQuery="DELETE FROM students WHERE id='$_POST[hidden]'";
mysql_query($DeleteQuery,$con);
};

if(isset($_POST['add'])){
$AddQuery="INSERT INTO students (id, name, password) VALUES ('$_POST[uid]','$_POST[uname]','$_POST[upassword]')";
mysql_query($AddQuery,$con);
};

//end query connection



$sql ="SELECT * FROM students";
$myData = mysql_query($sql,$con);
echo"<table border=1>
<tr>
<th>id</th>
<th>name</th>
<th>password</th>
</tr>";
while($record = mysql_fetch_array($myData)){
echo "<form action=stud_ac.php method=post>";
echo"<tr>";
echo"<td>" . "<input type = text name=id value=" . $record['id'] . " </td>";
echo"<td>" . "<input type = text name=name value=" . $record['name'] . " </td>";
echo"<td>" . "<input type = text name=password value=" . $record['password'] . " </td>";
echo"<td>" . "<input type = hidden name=hidden value=" . $record['id'] . " </td>";
echo"<td>" . "<input type = submit name=update value=update" . " </td>";
echo"<td>" . "<input type = submit name=delete value=delete" . " </td>";
echo"</tr>";
echo"</form>";
}
echo "<form action=stud_ac.php method=post>";
echo "<tr>";
echo "<td><input type=text name=uid></td>";
echo "<td><input type=text name=uname></td>";
echo "<td><input type=text name=upassword></td>";
echo "<td>" . "<input type = submit name=add value=add " . "</td>";
echo"</tr>";
echo "</form>";
echo "</table>";
mysql_close($con);

?>


	
</p>
					</div>
				</td>
		
				
			</tr>
		</table>
	
		
	<div id="main-footer">
		<p>Copyright &copy 2014. Powered by: Mythcrews Studios Pvt. Ltd </p>
	</div>	
	
	</div>
	
	</body>
	
	
		
	</head>
</html>




