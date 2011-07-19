<?php

# create our client object
$gmclient= new GearmanClient();

# add the default server (localhost)
$gmclient->addServer();

# run reverse client in the background

$job_handle = $gmclient->do("parser", "moods: sad likes: hello how are you hates: wtf?");
var_dump(json_decode($job_handle));

if ($gmclient->returnCode() != GEARMAN_SUCCESS)
{
  echo "bad return code\n";
  exit;
}


?>
