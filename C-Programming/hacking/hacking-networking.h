/* this function takes a socket and the buffer as input. it makes sure that all bytes are send. */
int send_string(int sockfd, unsigned char *buffer){

	int send_bytes, bytes_to_send;
	bytes_to_send = strlen(buffer);
	/* stay in that loop as long there are still bytes to send */
	while(bytes_to_send > 0){
		send_bytes=send(sockfd, buffer, bytes_to_send,0);
		if(send_bytes==-1)
			return 0;	/* indicates an error */
		bytes_to_send -= send_bytes;
		buffer += send_bytes;
	}
	return 1;			/* returns one when all data has been send */

}

/* this function accepts a socket and a pointer to a destination buffer. It reads from the socket until EOF byte sequence is seen. The EOL are read from the socket, but the destination
buffer is terminated before with '\0'. It returns the size of the read bytes in case of success, otherwise it returns 0 */
int recv_line(int sockfd, unsigned char *dest_buffer){

#define EOL "\r\n"		/* end of line byte sequence */
#define EOL_SIZE 2
	unsigned char *ptr;
	int eol_matched=0;

	ptr=dest_buffer;
	
	while(recv(sockfd, ptr, 1,0) ==1){
		if(*ptr == EOL[eol_matched]){
			eol_matched++;
			if(eol_matched == EOL_SIZE){
				*(ptr+1-EOL_SIZE) = '\0';	/* null terminates the string */
				return strlen(dest_buffer);
			}
		}
		else{
			eol_matched=0;
		}
	ptr++;		/* go to the next byte */
	}
	return 0;	/* did not find the end of line characters in the string */
}
