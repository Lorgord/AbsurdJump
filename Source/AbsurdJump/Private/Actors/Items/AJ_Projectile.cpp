// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Items/AJ_Projectile.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


AAJ_Projectile::AAJ_Projectile(const FObjectInitializer& ObjectInitializer)
{
// 	if (!RootComponent)
// {
//     RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
// }
//
// if (!CollisionComponent)
// {
//     // Use a sphere as a simple collision representation.
//     CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
//     // Set the sphere's collision profile name to "Projectile".
//     CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
//     // Event called when component hits something.
//     //CollisionComponent->OnComponentHit.AddDynamic(this, &AAJ_Projectile::OnHit);
//     // Set the sphere's collision radius.
//     CollisionComponent->InitSphereRadius(15.0f);
//     // Set the root component to be the collision component.
//     RootComponent = CollisionComponent;
// }
//
// if (!ProjectileMovementComponent)
// {
//     // Use this component to drive this projectile's movement.
//     ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
//     ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
//     ProjectileMovementComponent->InitialSpeed = 3000.0f;
//     ProjectileMovementComponent->MaxSpeed = 3000.0f;
//     ProjectileMovementComponent->bRotationFollowsVelocity = true;
//     ProjectileMovementComponent->bShouldBounce = true;
//     ProjectileMovementComponent->Bounciness = 0.3f;
//     //ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
// // }
// //
// // if (!ProjectileMesh)
// // {
// //     ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
// //     static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("'/Game/AbsurdJump/3D_Assets/Fruits/SM_Abrikos.SM_Abrikos'"));
// //     if (Mesh.Succeeded())
// //     {
// //         ProjectileMesh->SetStaticMesh(Mesh.Object);
// //     }
// //
// //     static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("'/Game/AbsurdJump/3D_Assets/Fruits/MI_Abrikos.MI_Abrikos'"));
// //     if (Material.Succeeded())
// //     {
// //         ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMesh);
// //     }
// //     ProjectileMesh->SetMaterial(0, ProjectileMaterialInstance);
// //     ProjectileMesh->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
// 	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
//     ProjectileMesh->SetupAttachment(RootComponent);
// }
//
// // Delete the projectile after 3 seconds.
// InitialLifeSpan = 3.0f;
// }
	 PrimaryActorTick.bCanEverTick = true;
	
	 RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileRoot"));
	
	 CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	 CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
	 //CollisionComponent->SetupAttachment(RootComponent);
	RootComponent = CollisionComponent;
	
	 ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	 ProjectileMesh->SetupAttachment(RootComponent);
	
	 ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComponent"));
	 ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	 ProjectileMovementComponent->bRotationFollowsVelocity = true;
	 ProjectileMovementComponent->bShouldBounce = true;
	
	 //InitialLifeSpan = 5.0f;
}

void AAJ_Projectile::BeginPlay()
{
	Super::BeginPlay();
}

void AAJ_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAJ_Projectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

