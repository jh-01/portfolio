<?php
  session_start();
  include_once "php/config.php";
  // if(!isset($_SESSION['unique_id'])){
  //   header("location: login.php");
  // }
  // if(!isset($user_id)){
  //   header("location: login.php");
  // }
?>
<?php include_once "header.php"; ?>
<body>
  <div class="header1">
		<input id="my-input" type="file" />
		<img class="img1" id="img1" src="img/copy.png" alt="갈무리" height="40" width="40" onclick="btn1_click();">
		<img class="img2" id="img2" src="img/disc.png" alt="미디어 업로드" height="40" width="40" onclick="btn2_click();">
	</div>
  <div class="wrapper">
    <section class="chat-area">
      <header>
          <a href="php/logout.php?logout_id=<?php echo $_SESSION['unique_id']; ?>" class='back-icon'><i class='fas fa-arrow-left'></i></a>
          <div class='details'>
          </div>
        </header>
      <div class="chat-box">
        <!-- <div class="chat outgoing">
          <div class="details">
            <p>Hi</p>
          </div>
        </div> -->
      </div>
      <form action="#" class="typing-area">
        <input type="text" name="message" class="input-field" placeholder="Type a message here..." autocomplete="off">
        <button class="btn"><i class="fab fa-telegram-plane"></i></button>
      </form>
    </section>
  </div>
  <div class="">
    <a href="php/logout.php?logout_id=<?php echo $_SESSION['unique_id']; ?>" class="logout">Logout</a>
  </div>

  <section class="users">
    <div class="users-list">

    </div>
  </section>

  <script src="javascript/chat.js"></script>
  <script src="javascript/main.js"></script>
  <script src="javascript/users.js"></script>

</body>
</html>
