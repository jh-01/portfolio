<?php
  session_start();
  if(isset($_SESSION['unique_id'])){
    header("location: chat.php");
  }

  if(!isset($_POST['userid'])){
    echo "
      <script>
        alert('로그인 후 입장해주세요.');
        location.href='http://prjshangrila38.dothome.co.kr/';
      </script>
    ";
  } else {
    $userid = $_POST['userid'];
  ?>
  <?php include_once "header.php"; ?>
      <body>
        <div class="wrapper">
          <section class="form login">
            <header>Realtime Chat App</header>
            <form action="#" method="POST" enctype="multipart/form-data" autocomplete="off">
              <div class="error-text"></div>
              <div class="field input">
                <label>Id</label>
                <input id="userid" type="text" name="userid" placeholder="Enter your ID" required>
              </div>
              <div class="field button">
                <input id="btn_submit" type="submit" name="submit" value="Continue to Chat">
              </div>
            </form>
          </section>
        </div>
        
        <script src="javascript/login.js"></script>

      </body>
      </html>

  <?php
  echo "
  		<script>
   			document.getElementById('userid').value='{$userid}';
  			document.getElementById('btn_submit').click();
  		</script>
  	";

} ?>

<?php //include_once "header.php"; ?>
<!-- <body>
  <div class="wrapper">
    <section class="form login">
      <header>Realtime Chat App</header>
      <form action="#" method="POST" enctype="multipart/form-data" autocomplete="off">
        <div class="error-text"></div>
        <div class="field input">
          <label>Id</label>
          <input id="userid" type="text" name="userid" placeholder="Enter your ID" required>
        </div>
        <div class="field input">
          <label>Password</label>
          <input id="pass" type="password" name="pass" placeholder="Enter your password" required>
          <i class="fas fa-eye"></i>
        </div>
        <div class="field button">
          <input id="btn_submit" type="submit" name="submit" value="Continue to Chat">
        </div>
      </form>
      <div class="link">Not yet signed up? <a href="index.php">Signup now</a></div>
    </section>
  </div>

  <script src="javascript/pass-show-hide.js"></script>
  <script src="javascript/login.js"></script>

</body>
</html> -->
