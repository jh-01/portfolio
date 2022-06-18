<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Site</title>
    <link rel="stylesheet" type="text/css" href="CSS/style.css?v1">
  </head>
  <body>
    <div class="main_box">
  		<h1 class="title">
  			<a href="index.html">
  				지상낙원프로젝트
  			</a>
  		</h1>
  		<div id="grid">
  			<div class="list">
  				<ol class="index">
  				<li><a href="1/1.php">소개</a></li>
  				<li><a href="2/2.php">공지</a></li>
  				<li><a href="3/3.php">예언</a></li>
  				<li>
				  <?php
						if(isset($_SESSION['userid'])){
							$id = $_SESSION['userid'];
							echo '
							<a href = "chat/login.php?id='.$id.' target="_blank">대화</a>							
							';
						} else {
							echo '
							<a href = "chat/login.php" target="_blank">대화</a>	
							';
						}
					?>
				</li>
  				</ol>
  			</div>
  		</div>

  		<div class="login" id="login">
  		  <a href="#" onclick="return false;" class="tri">▶</a>
  		  <a href="#" onclick="return false;" class="text1">이용자 ID를 입력하시거나 신규 회원의 경우 guest를 입력하십시오.</a>
  		  <div class="input">
  			<!-- <form class="" method="post" onsubmit="jbSubmit(); return false;"> -->
			<form class="" method="post" action="judge.php">
  			  <div class="text2">이용자 ID :</div>
  			  <input autocomplete="off" type="text" id="id" style="border:none" size="70" name="userid">
  			</form>

  			<script>
  				var input = document.getElementById("id");
  				input.addEventListener("keyup", function (event) {
  					if (event.keyCode === 13) {
  					  event.preventDefault();
  					  document.getElementById("myBtn").click();
  					}
  				});
  			</script>
  		  </div>
		  </div>
	   </div>
  </body>
</html>
