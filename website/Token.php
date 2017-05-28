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
   <li class='active has-sub'><a href="loginp.php"><span>LOG IN</span></a>
   
      <ul>
		
         <li class='has-sub'><a href="loginp.php"><span>Admin</span></a></li>
         <li class='has-sub'><a href="teachlog.php"><span>Teachers</span></a></li>
         <li class='has-sub'><a href="studlog.php"><span>Students</span></a></li>
      </ul>
   </li>
</ul>
</div>
<td width="1000">
		<table>
			<tr>
				
				<td width="150">
					<div class="left_bar">
						
						
						<?php	
						
						for($i=0;$i<=17;$i++)
						{
							echo "&nbsp<br>"; 
						}
						?>
						
					</div>
				</td>
				
				<td width="900">
					<div class="mid">
						<h1>Merit Records</h1>
						<p> Merit point and Demerit Points are one of the unique feature of Rambhakta Memorial School. Every student from class four to
							class ten gets a unique id under their name. These id holds their merit points as well as demerit points of each and every 
							subject including extra activities. Following points describes about extra tokens.</p>
							<ul>
								<li><i>Rules related to extra tokens<i></li>
								<li>Students get C merit Card if they collect 5 tokens of Extra Activities<li>
								<li>Students can collect B merit Card if they collect 5 C merit Card</li>
								<li>Students can collect A merit Card if they collect 5 B merit Card</li>
								<li>Students collecting A merit card will be awarded with exclusive gifts and prizes from school</li>
								<li>If students are found on any activities against the school's rules and regulations, demerit pointw will be provided</li>
								<li>Demerit points will be provided according to the nature of the rules and regulations broken</i></li>
							</ul>
							<p> On the demerit point of extra activities following rules are implemented</p>
							<ul>
								<li><i>If students get demerit point -5, they are warned and told to deduct it<li>
								<li>If the student doesn't deduct his demerit points for a week then it is officially announced as -5</li>
								<li>Officially announced "-5" listed students are not allowed to participate in any kind of school activities like tours, sport events, compititions, excursions etc.</li>
								<li>The enlisted students in "-5" are forbidden till the upcoming terminal evaluation</li>
								<li>If students get -10 demerit points then they are forbidden in school activities for whole year</i></li>
							</ul>
							<p>In case of other subject tokens there are no such rules as in extra but if they dont exceed 16 tokens in any subject 
								then they cannot appear in the terminal examination. The no. of tokens effect in the final grade sheet as merit points covers
								40% of the total evaluation.
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