int main() {
	*(unsigned char *)(0xB8000) = 'A';
	*(unsigned char *)(0xB8001) = 'A';
	for(;;);
}
