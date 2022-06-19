<?php
if($_POST['userid'] === '/x'){
  echo "<script>location.href='../index.html'</script>";
} 

?>

<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Signup Page</title>
    <link rel="stylesheet" type="text/css" href="style.css?v1">
  </head>
  <body>
    <div class="intro2">
        <h4 class="title2">입력린에 /x 를 입력하면 가입을 중단합니다.</h4>
        <p class="info1">1. 아이디를 입력해주세요</p>
        <p class="info1">>> <?php echo $_POST['userid'];?></p>
        <p class="info2">2. 비밀번호를 입력해주세요</p>
        <div class="input2">
          <form class="" method="post" action="3.php">
            <div class="text2">>> </div>
            <input type="hidden" id="id" class="id" style="border:none" size="70" name="userid" value="<?=$_POST['userid']?>">
            <input type="text" id="pass" class="pass" style="border:none" size="70" name="pass">
          </form>
        </div>
    </div>
  </body>
</html>
