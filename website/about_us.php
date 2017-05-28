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
   <li class='last'><a href="about_us.php"><span>About Us</span></a></li>
   <li class='active has-sub'><a href="login.php"><span>LOG IN</span></a>
      <ul>
         <li class='has-sub'><a href="loginp.php"><span>Admin</span></a></li>
         <li class='has-sub'><a href="teachlog.php"><span>Teachers</span></a></li>
         <li class='has-sub'><a href="studlog.php"><span>Students</span></a></li>
      </ul>
   </li>
</ul>
</div>

	<table>
			<tr>
				
				<td width="150">
					<div class="left_bar">
					<div class = "leftside">
					   <?php 
					   include"calendar.php";
					   ?>
					   <br> 
					   <div>
						<?php	
						
						for($i=0;$i<=29;$i++)
						{
							echo ".<br>";
						}
						?>
					</div>
					<div>
 
					
				</td>
				
				<td width="900">
					<div class="mid">
					<h1>About Us</h1>
					<img src="info.jpg" height="50%" width="100%" alt="RMS_logo" align="center">
						<p>
							RMS takes annual entrance exam for the new students at the month of CHAITRA every year. The selected candidates after<br>
							entrance test can do their admissions to join RMS. <br>
							This year the the date for form distribution  starts from 25 of CHAITRA. The final date to collect the form for entrance <br>
							examination is 28th CHAITRA.<br>
							<br> There isn't yearly admission system in RMS. A student should do their admission only three times in his time in RMS.<br>
							The students have to do their admission for KINDERGARTEN, CLASS ONE and CLASS SIX. In the name of yearly admission the <br>
							students fee for the month of BAISHAK should should be paid. After the payment of the fee for BAISHAK the students can get<br>
							their roll number. 
							<br><br>
							Detail information on the admission process and fee stucture is gien bellow.<br>
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
