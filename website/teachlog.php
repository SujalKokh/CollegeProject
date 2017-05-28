<?php
session_start();


?>

<html>
	<head>
		<title>Welcome to RMS Login Page</title>
</head>
	
<body background="back.jpg"align='center'>
<table>
<tr>


	<td height="118"><img src="LOGO.jpg" height = 50 width = 50"> <font face = "verdana" size = 12 color = "white"> RAMBHAKTA MEMORIAL SCHOOL
	
	
	</font>	
	
</tr>
</table>
<hr>

<form method='post' action='teachlog.php'>
	
	<div id= "container" background="back.jpg" >
	
	<table width='400' align='center'>
		
	
	<tr>
		<td><font color="white" size=4 face="Comic Sans MS">UserName:</font></td>
		<td><input type='text' name='name'/></td>
	</tr>
	<tr>
		<td><font color="white" size=4 face="Comic Sans MS">Password:</font></td>
		<td><input type="password" name='password'/></td>
	</tr>
	<tr>
		<td colspan='3' align='center'><input type="submit" name='login' value="login"/></td>
	</tr>
</table>
</div>
</font>
</form>
<center><font color="white" size=6>Sign In as</font><br><a href='contact.php'><font color="white"size=7>Teacher</font></a>

</center></font>
</body>
</html>

<?php
mysql_connect("localhost","root","");
mysql_select_db("rms");

if (isset($_POST['login']))
{
	$name =htmlentities($_POST["name"]);
	$password =htmlentities($_POST["password"]);
	
	$check_name="select * from teachers where
	password='$password' AND name='$name'";
	
	$run=mysql_query($check_name);
	
	if(mysql_num_rows($run)>0)
	{
	
		$_SESSION['name']=$name;
	
		echo "<script>window.open('login_teacher.php','_self')</script>";
	}
	
	else
	{
		echo "<font color='#B40707'><center><b>Email or Password is incorrect!!! Please try again.</b></center></font>";
	}
}
?>
