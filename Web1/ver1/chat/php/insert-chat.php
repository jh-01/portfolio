<?php
    session_start();
    if(isset($_SESSION['unique_id'])){
        include_once "config.php";
        $outgoing_id = $_SESSION['unique_id'];
        $message = mysqli_real_escape_string($conn, $_POST['message']);
        if(!empty($message)){
            $sql = mysqli_query($conn, "INSERT INTO messages (outgoing_msg_id, msg, notice)
                                        VALUES ({$outgoing_id}, '{$message}', 1 )") or die();
        }
    } else{
        header("location: ../login.php");
    }



?>
