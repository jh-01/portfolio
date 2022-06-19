<?php
    while($row = mysqli_fetch_assoc($query)){

        ($row['status'] == "Offline now") ? $offline = "offline" : $offline = "";
        ($outgoing_id == $row['unique_id']) ? $hid_me = "hide" : $hid_me = "";

        $output .= '<a href="chat.php?user_id='. $row['userid'] .'">
                    <div class="content">
                    <div class="details">
                        <span>'. $row['userid'] .'</span>
                    </div>
                    </div>
                    <div class="status-dot '. $offline .'"><i class="fas fa-circle"></i></div>
                </a>';
    }
?>
