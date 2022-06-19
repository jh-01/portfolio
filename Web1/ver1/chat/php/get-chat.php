<?php
    session_start();
    if(isset($_SESSION['unique_id'])){
      include_once "config.php";
      $outgoing_id = $_SESSION['unique_id'];
  		$output = "";
  		$sql = "SELECT * FROM messages LEFT JOIN members ON members.unique_id = messages.outgoing_msg_id
                  ORDER BY msg_id";
  		$query = mysqli_query($conn, $sql);
  		if(mysqli_num_rows($query) > 0){
  			while($row = mysqli_fetch_assoc($query)){
  				if($row['notice'] == 1){
  					$output .= '
                          <table class="chat incoming">
                            <th class="chat_name">'.$row['userid'].'</th>
                            <th class="chat_userid">('.$row['userid'].')</th>
                            <th class="blank">:  </th>
                            <th class="chat_msg">'. $row['msg'] .'</th>
                          </table>
                  ';
  				   } else if($row['notice'] == 2){
               $output .= '
                <div class="notice">※ '.$row['userid'].'('.$row['userid'].')님이 입장하셨습니다. ※</div>
              ';
             } else {
               $output .= '
                <div class="notice">※'.$row['userid'].'('.$row['userid'].')님이 퇴장하셨습니다.※</div>
              ';
             }
  			   }
		    }else{
			       $output .= '<div class="text">No messages are available. Once you send message they will appear here.</div>';
		  }
		  echo $output;
    }else{
        header("location: ../../index.html");
    }

?>
