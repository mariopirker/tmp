<form method="POST" action="revision.php">
<b>Barracuda Networks - Serial to Revision Converter:</b><br><br>
<b>Please enter the serial number: </b>
<input name="serialnumber" size=6><br>
<input type=submit name=submit value="Convert">
</form>

<?php 

if (!empty($_POST["submit"])){

	$sn = $_POST["serialnumber"];
	$post_data_vars = array(
		'option'    => 'onlinesale',
		'serial'    => $post['serial_number'],
		'product'   => $post['product'],
		'domain'    => (isset($post['default_domain'])? $post['default_domain'] : 'barracuda.com')
	);
          
	$post_data = build_query_string($post_data_vars);
	$result = http_curl_post("https://ops.barracuda.com/cgi-bin/online_check.cgi", $post_data, 'engineering', 's3cr3tG0DS', false);


	if($result=="BAB"){
		print "Revision B\n";
	}
 
function build_query_string($vars) {
      if(!is_array($vars)) return '';
      reset($vars);
      $tmp = array();
      while(list($key, $value) = each($vars))
            $tmp[] = urlencode($key) . '=' . urlencode($value);
      return implode('&', $tmp);
}
 

function http_curl_post($url, $data, $user = '', $pass = '', $include_header = false) {
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_VERBOSE, 0);
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 0);
    curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 0);
    if($user && $pass) {
        curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
        curl_setopt($ch, CURLOPT_USERPWD, "$user:$pass");
    }
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 8);
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_POST, 1);
    curl_setopt($ch, CURLOPT_HEADER, $include_header);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $data);
 
    $result = curl_exec($ch);
    curl_close($ch);
    return $result;
}

} // end if 
?>
