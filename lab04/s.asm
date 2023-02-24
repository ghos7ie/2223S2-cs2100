.data
count: .word 0

.text
    lw      $t6,        count

# read in 8 values
    add     $t0,        $t0,    $0      # start
    addi    $t1,        $t1,    32      # end

# loop for taking in 8 values
readloop:
    slt     $t9,        $t0,    $t1     # see if start > end
    beq     $t9,        $0,     next    # move to next if finished
    li      $v0,        5
    syscall 
    la      $t8,        0($v0)          # store into t8
    sw      $t8,        0($t0)          # store into s1
    addi    $t0,        $t0,    4       # increment start by 1
    j       readloop

next:

# read in user value for X
    li      $v0,        5               # syscall for read_int
    syscall 
    move    $s3,        $v0             # move

# read in 8 values
    addi    $t1,        $t1,    32      # end
    addi    $t0,        $t0,    -32     # reset s1 to starting address
    addi    $s4,        $s3,    -1      # generate mask of X

loop:
    slt     $t9,        $t0,    $t1     # see if start > end
    beq     $t9,        $0,     term
    lw      $t4,        0($t0)          # load element
    and     $t5,        $t4,    $s4
    bne     $t5,        $0,     skip
    addi    $t6,        $t6,    1

skip:
    addi    $t0,        $t0,    4
    j       loop

term:
    li      $v0,        1               # system call code for print_int
    move    $a0,        $t6             # integer to print
    syscall                             # print the integer

# code for terminating program
    li      $v0,        10
    syscall 