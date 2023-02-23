.data
array: .word 8, 2, 10, 23, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6
my_string: .asciiz "s1 val:"
.text
    la      $s0,    array                                       # load array
    add     $s1,    $zero,      $zero                           # initalise starting counter
    addi    $t0,    $s0,        16                              # initialise array size
here:
    addi    $t0,    $t0,        -4
    lw      $t1,    0($t0)
    li      $v0,    1
    move    $a0,    $t1
    syscall 
    li      $v0,    11                                          # system call code for printing a character
    li      $a0,    10                                          # ASCII code for newline character
    syscall                                                     # print the character
    slti    $t2,    $t1,        8
    bne     $t2,    $zero,      skip
    addi    $s1,    $s1,        1
    sll     $s1,    $s1,        1
skip:
    beq     $t0,    $s0,        end
    j       here
end:
    la      $a0,    my_string                                   # load the address of the string into register $a0
    li      $v0,    4                                           # system call code for printing a string
    syscall                                                     # call the system call to print the string
    li      $v0,    1
    move    $a0,    $s1
    syscall 
    li      $v0,    11                                          # system call code for printing a character
    li      $a0,    10                                          # ASCII code for newline character
    syscall                                                     # print the newline character
    li      $v0,    10                                                            # code for terminating program
    syscall 