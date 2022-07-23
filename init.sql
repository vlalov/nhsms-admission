if not exists (select * from sysusers where name = N'operator' and uid > 16399)
	EXEC sp_addrole N'operator'
GO

CREATE TABLE [dbo].[ExamsResults] (
	[N] [int] IDENTITY (1, 1) NOT NULL ,
	[ID] [int] NOT NULL ,
	[Person_ID] [int] NOT NULL ,
	[Exam] [int] NOT NULL ,
	[Points] [decimal](18, 2) NULL ,
	[Score] [decimal](18, 2) NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Persons] (
	[ID] [int] NOT NULL ,
	[Name] [varchar] (200) NOT NULL ,
	[PreferedSchool] [bit] NOT NULL ,
	[EGN] [varchar] (10) NOT NULL ,
	[Telephone] [varchar] (50) NOT NULL ,
	[Address] [varchar] (200) NULL ,
	[Sex] [int] NOT NULL ,
	[Tax_id] [int] NOT NULL ,
	[Room_Code] [varchar] (10) NULL ,
	[EntOn] [datetime] NULL ,
	[EntBy] [varchar] (50) NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Persons_History] (
	[DateChanged] [datetime] NOT NULL ,
	[ChangedBy] [varchar] (50) NOT NULL ,
	[Comment] [varchar] (20) NULL ,
	[ID] [int] NOT NULL ,
	[Name] [varchar] (200) NOT NULL ,
	[EGN] [varchar] (10) NOT NULL ,
	[Telephone] [varchar] (50) NOT NULL ,
	[Address] [varchar] (200) NULL ,
	[Sex] [int] NOT NULL ,
	[Tax_id] [int] NOT NULL ,
	[Room_Code] [varchar] (10) NULL ,
	[EntOn] [datetime] NULL ,
	[EntBy] [varchar] (50) NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Places] (
	[ID] [int] NOT NULL ,
	[Name] [varchar] (100) NOT NULL ,
	[Text] [varchar] (100) NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[PointsToScore] (
	[Profile_ID] [int] NOT NULL ,
	[Point] [decimal](18, 2) NOT NULL ,
	[Score] [decimal](18, 2) NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Profiles] (
	[ID] [int] NOT NULL ,
	[Name] [varchar] (50) NOT NULL ,
	[DiffMW] [bit] NOT NULL ,
	[Space] [int] NOT NULL ,
	[SpaceOther] [int] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Profiles_History] (
	[Grade] [int] NOT NULL ,
	[ID] [int] NOT NULL ,
	[DiffMW] [bit] NOT NULL ,
	[Space] [int] NOT NULL ,
	[SpaceOther] [int] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Register] (
	[Classificated] [bit] NOT NULL ,
	[Profile_ID] [int] NOT NULL ,
	[Person_ID] [int] NOT NULL ,
	[Amount] [decimal](18, 2) NOT NULL ,
	[IsIn] [bit] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Register_Catalog] (
	[Grade] [int] NOT NULL ,
	[Information] [varchar] (150) NULL ,
	[EntOn] [datetime] NOT NULL ,
	[EntBy] [varchar] (50) NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Register_History] (
	[Grade] [int] NOT NULL ,
	[Classificated] [bit] NOT NULL ,
	[Person_ID] [int] NOT NULL ,
	[Profile_ID] [int] NOT NULL ,
	[Amount] [decimal](18, 2) NOT NULL ,
	[IsIn] [bit] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[RegisterNum] (
	[RegisterNumber] [int] NOT NULL ,
	[RegisterIndex] [int] NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Rooms] (
	[Place_ID] [int] NOT NULL ,
	[Capacity] [int] NOT NULL ,
	[Code] [varchar] (10) NOT NULL ,
	[Comment] [varchar] (100) NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Taxes] (
	[ID] [int] NOT NULL ,
	[Value] [money] NOT NULL ,
	[Name] [varchar] (50) NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[UserTexts] (
	[ID] [int] NOT NULL ,
	[Value] [text] NULL 
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO

CREATE TABLE [dbo].[Wishes] (
	[Person_ID] [int] NOT NULL ,
	[Profile_ID] [int] NOT NULL ,
	[Priority] [int] NOT NULL ,
	[Score] [decimal](18, 2) NOT NULL ,
	[FromOlymp] [bit] NOT NULL ,
	[OlympScore] [decimal](18, 2) NULL ,
	[GoToExam] [bit] NOT NULL ,
	[EntOn] [datetime] NULL ,
	[EntBy] [varchar] (50) NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Wishes_Deleted] (
	[Person_ID] [int] NOT NULL ,
	[Priority] [int] NOT NULL ,
	[GoToExam] [bit] NOT NULL ,
	[DelOn] [datetime] NULL ,
	[DelBy] [varchar] (50) NULL 
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[Wishes_History] (
	[DateChanged] [datetime] NOT NULL ,
	[ChangedBy] [varchar] (50) NOT NULL ,
	[Comment] [varchar] (20) NULL ,
	[Person_ID] [int] NOT NULL ,
	[Profile_ID] [int] NOT NULL ,
	[Priority] [int] NOT NULL ,
	[Score] [decimal](18, 2) NOT NULL ,
	[FromOlymp] [bit] NOT NULL ,
	[OlympScore] [decimal](18, 2) NULL ,
	[GoToExam] [bit] NOT NULL ,
	[EntOn] [datetime] NULL ,
	[EntBy] [varchar] (50) NULL 
) ON [PRIMARY]
GO

ALTER TABLE [dbo].[ExamsResults] WITH NOCHECK ADD 
	CONSTRAINT [CK_ExamsResults] CHECK ([Score] >= 2 and [Score] <= 6)
GO

ALTER TABLE [dbo].[Persons] WITH NOCHECK ADD 
	CONSTRAINT [DF_Persons_PreferedSchool] DEFAULT (1) FOR [PreferedSchool],
	CONSTRAINT [DF_Persons_Sex] DEFAULT (1) FOR [Sex],
	CONSTRAINT [DF_Persons_Tax_id] DEFAULT (1) FOR [Tax_id],
	CONSTRAINT [DF_Persons_EntOn] DEFAULT (getdate()) FOR [EntOn],
	CONSTRAINT [DF_Persons_EntBy] DEFAULT (user_name()) FOR [EntBy],
	CONSTRAINT [PK_Persons] PRIMARY KEY  NONCLUSTERED 
	(
		[ID]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[Persons_History] WITH NOCHECK ADD 
	CONSTRAINT [DF_Persons_History_DateChanged] DEFAULT (getdate()) FOR [DateChanged],
	CONSTRAINT [DF_Persons_History_ChangedBy] DEFAULT (user_name()) FOR [ChangedBy]
GO

ALTER TABLE [dbo].[Places] WITH NOCHECK ADD 
	CONSTRAINT [PK_Places] PRIMARY KEY  NONCLUSTERED 
	(
		[ID]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[PointsToScore] WITH NOCHECK ADD 
	CONSTRAINT [CK_PointsToScore_Score] CHECK ([Score] >= 2 and [Score] <= 6)
GO

ALTER TABLE [dbo].[Profiles] WITH NOCHECK ADD 
	CONSTRAINT [DF_Profiles_DiffMW] DEFAULT (0) FOR [DiffMW],
	CONSTRAINT [DF_Profiles_SpaceOther] DEFAULT (0) FOR [SpaceOther],
	CONSTRAINT [PK_Profiles] PRIMARY KEY  NONCLUSTERED 
	(
		[ID]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[Profiles_History] WITH NOCHECK ADD 
	CONSTRAINT [DF_Profiles_History_DiffMW] DEFAULT (0) FOR [DiffMW],
	CONSTRAINT [DF_Profiles_History_SpaceOther] DEFAULT (0) FOR [SpaceOther]
GO

ALTER TABLE [dbo].[Register] WITH NOCHECK ADD 
	CONSTRAINT [DF_Register_UPPER_IsIn] DEFAULT (0) FOR [IsIn]
GO

ALTER TABLE [dbo].[Register_Catalog] WITH NOCHECK ADD 
	CONSTRAINT [DF_Register_Catalog_EntOn] DEFAULT (getdate()) FOR [EntOn],
	CONSTRAINT [DF_Register_Catalog_EntBy] DEFAULT (user_name()) FOR [EntBy]
GO

ALTER TABLE [dbo].[RegisterNum] WITH NOCHECK ADD 
	CONSTRAINT [DF_RegisterNum_RegisterNumber] DEFAULT (1) FOR [RegisterNumber],
	CONSTRAINT [CK_RegisterNum] CHECK ([RegisterNumber] > 0)
GO

ALTER TABLE [dbo].[Rooms] WITH NOCHECK ADD 
	CONSTRAINT [CK_Rooms] CHECK ([Capacity] > 0)
GO

ALTER TABLE [dbo].[Taxes] WITH NOCHECK ADD 
	CONSTRAINT [PK_Taxes] PRIMARY KEY  NONCLUSTERED 
	(
		[ID]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[UserTexts] WITH NOCHECK ADD 
	CONSTRAINT [PK_UserTexts] PRIMARY KEY  NONCLUSTERED 
	(
		[ID]
	)  ON [PRIMARY] 
GO

ALTER TABLE [dbo].[Wishes] WITH NOCHECK ADD 
	CONSTRAINT [DF_Wishes_FromOlymp] DEFAULT (0) FOR [FromOlymp],
	CONSTRAINT [DF_Wishes_GoToExam] DEFAULT (1) FOR [GoToExam],
	CONSTRAINT [DF_Wishes_EntOn] DEFAULT (getdate()) FOR [EntOn],
	CONSTRAINT [DF_Wishes_EntBy] DEFAULT (user_name()) FOR [EntBy],
	CONSTRAINT [CK_Wishes_OlympScore] CHECK ([OlympScore] >= 2 and [OlympScore] <= 6),
	CONSTRAINT [CK_Wishes_Score] CHECK ([Score] >= 2 and [Score] <= 6)
GO

ALTER TABLE [dbo].[Wishes_Deleted] WITH NOCHECK ADD 
	CONSTRAINT [DF_Wishes_Deleted_GoToExam] DEFAULT (1) FOR [GoToExam],
	CONSTRAINT [DF_Wishes_Deleted_DelOn] DEFAULT (getdate()) FOR [DelOn],
	CONSTRAINT [DF_Wishes_Deleted_DelBy] DEFAULT (user_name()) FOR [DelBy]
GO

ALTER TABLE [dbo].[Wishes_History] WITH NOCHECK ADD 
	CONSTRAINT [DF_Wishes_History_DateChanged] DEFAULT (getdate()) FOR [DateChanged],
	CONSTRAINT [DF_Wishes_History_ChangedBy] DEFAULT (user_name()) FOR [ChangedBy]
GO

 CREATE  UNIQUE  INDEX [IX_ExamsResults_Person] ON [dbo].[ExamsResults]([Person_ID], [Exam]) ON [PRIMARY]
GO

 CREATE  UNIQUE  INDEX [IX_ExamsResults_Exam] ON [dbo].[ExamsResults]([ID], [Exam]) ON [PRIMARY]
GO

 CREATE  UNIQUE  INDEX [IX_Persons_EGN] ON [dbo].[Persons]([EGN]) ON [PRIMARY]
GO

 CREATE  UNIQUE  INDEX [IX_PointsToScore_Point] ON [dbo].[PointsToScore]([Profile_ID], [Point]) ON [PRIMARY]
GO

 CREATE  UNIQUE  INDEX [IX_Register_UPPER] ON [dbo].[Register]([Profile_ID], [Person_ID]) ON [PRIMARY]
GO

 CREATE  UNIQUE  INDEX [IX_RegisterNum] ON [dbo].[RegisterNum]([RegisterNumber]) ON [PRIMARY]
GO

 CREATE  UNIQUE  INDEX [IX_Rooms_Code] ON [dbo].[Rooms]([Code]) ON [PRIMARY]
GO

 CREATE  UNIQUE  INDEX [IX_Wishes_Prof] ON [dbo].[Wishes]([Person_ID], [Profile_ID]) ON [PRIMARY]
GO

 CREATE  UNIQUE  INDEX [IX_Wishes_Prior] ON [dbo].[Wishes]([Person_ID], [Priority]) ON [PRIMARY]
GO

 CREATE  UNIQUE  INDEX [IX_Wishes_Deleted] ON [dbo].[Wishes_Deleted]([Person_ID], [Priority], [DelOn], [DelBy]) ON [PRIMARY]
GO

GRANT  SELECT ,  INSERT ,  DELETE ,  UPDATE  ON [dbo].[ExamsResults]  TO [operator]
GO

GRANT  SELECT ,  INSERT ,  DELETE ,  UPDATE  ON [dbo].[Persons]  TO [operator]
GO

DENY  SELECT ,  INSERT ,  DELETE ,  UPDATE  ON [dbo].[Persons_History]  TO [operator] CASCADE 
GO

GRANT  SELECT  ON [dbo].[Places]  TO [operator]
GO

DENY  INSERT ,  DELETE ,  UPDATE  ON [dbo].[Places]  TO [operator] CASCADE 
GO

GRANT  SELECT ,  INSERT ,  DELETE ,  UPDATE  ON [dbo].[PointsToScore]  TO [operator]
GO

GRANT  SELECT  ON [dbo].[Profiles]  TO [operator]
GO

DENY  INSERT ,  DELETE ,  UPDATE  ON [dbo].[Profiles]  TO [operator] CASCADE 
GO

GRANT  SELECT  ON [dbo].[Profiles_History]  TO [operator]
GO

GRANT  SELECT ,  INSERT  ON [dbo].[Register]  TO [operator]
GO

DENY  DELETE ,  UPDATE  ON [dbo].[Register]  TO [operator] CASCADE 
GO

GRANT  SELECT  ON [dbo].[Register_Catalog]  TO [operator]
GO

GRANT  SELECT  ON [dbo].[Register_History]  TO [operator]
GO

GRANT  SELECT  ON [dbo].[RegisterNum]  TO [operator]
GO

DENY  INSERT  ON [dbo].[RegisterNum]  TO [operator] CASCADE 
GO

GRANT  SELECT  ON [dbo].[Rooms]  TO [operator]
GO

DENY  INSERT ,  DELETE ,  UPDATE  ON [dbo].[Rooms]  TO [operator] CASCADE 
GO

GRANT  SELECT  ON [dbo].[Taxes]  TO [public]
GO

GRANT  SELECT  ON [dbo].[Taxes]  TO [operator]
GO

DENY  INSERT ,  DELETE ,  UPDATE  ON [dbo].[Taxes]  TO [operator] CASCADE 
GO

GRANT  SELECT  ON [dbo].[UserTexts]  TO [operator]
GO

DENY  INSERT ,  DELETE ,  UPDATE  ON [dbo].[UserTexts]  TO [operator] CASCADE 
GO

GRANT  SELECT ,  INSERT ,  DELETE ,  UPDATE  ON [dbo].[Wishes]  TO [operator]
GO

GRANT  SELECT  ON [dbo].[Wishes_Deleted]  TO [operator]
GO

DENY  SELECT ,  INSERT ,  DELETE ,  UPDATE  ON [dbo].[Wishes_History]  TO [operator] CASCADE 
GO

ALTER TABLE [dbo].[ExamsResults] ADD 
	CONSTRAINT [FK_ExamsResults_Persons] FOREIGN KEY 
	(
		[Person_ID]
	) REFERENCES [dbo].[Persons] (
		[ID]
	)
GO

ALTER TABLE [dbo].[Persons] ADD 
	CONSTRAINT [FK_Persons_Rooms] FOREIGN KEY 
	(
		[Room_Code]
	) REFERENCES [dbo].[Rooms] (
		[Code]
	)
GO

ALTER TABLE [dbo].[Register] ADD 
	CONSTRAINT [FK_Register_UPPER_Persons] FOREIGN KEY 
	(
		[Person_ID]
	) REFERENCES [dbo].[Persons] (
		[ID]
	),
	CONSTRAINT [FK_Register_UPPER_Profiles] FOREIGN KEY 
	(
		[Profile_ID]
	) REFERENCES [dbo].[Profiles] (
		[ID]
	)
GO

ALTER TABLE [dbo].[Rooms] ADD 
	CONSTRAINT [FK_Rooms_Places] FOREIGN KEY 
	(
		[Place_ID]
	) REFERENCES [dbo].[Places] (
		[ID]
	)
GO

ALTER TABLE [dbo].[Wishes] ADD 
	CONSTRAINT [FK_Wishes_Persons] FOREIGN KEY 
	(
		[Person_ID]
	) REFERENCES [dbo].[Persons] (
		[ID]
	),
	CONSTRAINT [FK_Wishes_Profiles] FOREIGN KEY 
	(
		[Profile_ID]
	) REFERENCES [dbo].[Profiles] (
		[ID]
	)
GO

SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO




CREATE VIEW dbo.V_PersonsTaxes
AS
SELECT p.ID, p.Name, p.EntOn, p.EntBy, (COUNT(w.Priority) + 1) 
    * tax.Value AS Tax
FROM Persons p INNER JOIN
    Taxes tax ON p.Tax_id = tax.ID AND 
    p.Tax_id = tax.ID FULL OUTER JOIN
    Wishes w ON p.ID = w.Person_ID
WHERE w.GoToExam = 1
GROUP BY p.ID, p.Name, p.EntOn, p.EntBy, tax.Value




GO
SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO

SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO




CREATE PROCEDURE CURRENTDATE @inp DATETIME AS

SELECT DATEDIFF(d,@inp,getdate())



GO
SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO

SET QUOTED_IDENTIFIER  ON    SET ANSI_NULLS  ON 
GO




CREATE TRIGGER CheckCorrectPID ON dbo.ExamsResults 
FOR INSERT, UPDATE 
AS
DECLARE 
	@pid integer,
	@ex  integer
SELECT @pid=i.Person_ID,@ex=i.Exam FROM inserted i

IF (@ex!=0)
BEGIN 
  	IF NOT EXISTS(SELECT * FROM  Wishes w WHERE w.Person_ID=@pid AND w.Profile_ID=@ex AND w.GoToExam=1)
	BEGIN
		RAISERROR('Кандидата не е пожелал такъв изпит!',16,1)
		ROLLBACK TRANSACTION
	END
END





GO
SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO

SET QUOTED_IDENTIFIER  ON    SET ANSI_NULLS  ON 
GO

CREATE TRIGGER Persons_UpdHist_TRG1 ON dbo.Persons 
FOR UPDATE
AS
INSERT Persons_History(Comment,ID,Name,EGN,Telephone,Address,Sex,
	Tax_id,EntOn,EntBy,Room_Code)
SELECT '- Променен -',d.ID,d.Name,d.EGN,d.Telephone,d.Address,d.Sex,d.Tax_id,d.EntOn,d.EntBy,Room_Code FROM deleted d

GO
SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO

SET QUOTED_IDENTIFIER  ON    SET ANSI_NULLS  ON 
GO

CREATE TRIGGER Persons_DelHist_TRG1 ON dbo.Persons 
FOR DELETE
AS
DECLARE @person integer

INSERT Persons_History(Comment,ID,Name,EGN,Telephone,Address,Sex,
	Tax_id,EntOn,EntBy,Room_Code)
SELECT '- Изтрит -',d.ID,d.Name,d.EGN,d.Telephone,d.Address,d.Sex,d.Tax_id,d.EntOn,d.EntBy,Room_Code FROM deleted d

-- Deleting all History of deleted wishes
SELECT @person=d.ID FROM deleted d

DELETE FROM Wishes_Deleted 
WHERE Person_ID=@person


GO
SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO

SET QUOTED_IDENTIFIER  ON    SET ANSI_NULLS  ON 
GO




CREATE TRIGGER CheckProfile_TRG1 ON dbo.PointsToScore 
FOR INSERT, UPDATE
AS
DECLARE
 @prof integer,
 @cnt integer

SELECT @prof=i.Profile_ID FROM inserted i

SELECT @cnt=COUNT(*) FROM Profiles WHERE ID=@prof

IF NOT (@prof=0 OR @cnt>0) 
BEGIN 
   RAISERROR('Несъществуващ профил!',16,1)
   ROLLBACK TRANSACTION
END




GO
SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO

SET QUOTED_IDENTIFIER  ON    SET ANSI_NULLS  ON 
GO

CREATE TRIGGER Delete_Profiles ON dbo.Register_Catalog 
FOR DELETE 
AS
DECLARE @grade int
SELECT @grade=d.Grade FROM deleted d
DELETE FROM Profiles_History WHERE Grade=@grade 
DELETE FROM Register_History WHERE Grade=@grade

GO
SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO

SET QUOTED_IDENTIFIER  ON    SET ANSI_NULLS  ON 
GO

CREATE TRIGGER Insert_Profiles_History ON dbo.Register_Catalog 
FOR INSERT
AS
DECLARE @grade int
SELECT @grade=i.Grade FROM inserted i

INSERT INTO Profiles_History(Grade,ID,DiffMW,Space,SpaceOther) 
SELECT @grade,pr.ID,pr.DiffMW,pr.Space,pr.SpaceOther FROM Profiles pr 

INSERT INTO Register_History(Grade,Classificated,Person_id,Profile_id,Amount,isin) 
SELECT @grade,r.Classificated,r.Person_id,r.Profile_id,r.Amount,r.IsIn FROM Register r

GO
SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO

SET QUOTED_IDENTIFIER  ON    SET ANSI_NULLS  ON 
GO




CREATE TRIGGER Control_Priority_TRG1 ON [Wishes] 
FOR INSERT, UPDATE 
AS
DECLARE 
	@cnt_profiles integer,
	@prior integer
-- Checking Priority...
SELECT @cnt_profiles=COUNT(*) FROM Profiles
SELECT @prior=i.Priority FROM inserted i
IF (@prior>@cnt_profiles OR @prior<0) 
BEGIN
	RAISERROR('Грешен приоритет!',16,1)
	ROLLBACK TRANSACTION
END






GO
SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO

SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO




CREATE TRIGGER Wishes_UpdEnt_TRG1 ON dbo.Wishes 
FOR UPDATE AS
DECLARE 
	@cnt_profiles integer,
	@prior integer,
	@newGoTo bit,
	@oldGoTo bit,
	@fromolymp bit,
	@olympscore float
-- Checking Priority...
SELECT @cnt_profiles=COUNT(*) FROM Profiles
SELECT @prior=i.Priority FROM inserted i
IF (@prior>@cnt_profiles) 
BEGIN
	RAISERROR('Грешен приоритет!',16,1)
	ROLLBACK TRANSACTION
END
-- Checking Olymp datas
SELECT @fromolymp=i.FromOlymp,@olympscore=i.OlympScore,@newGoTo=i.GoToExam

FROM inserted i

IF (@fromolymp=0 AND @olympscore IS NOT NULL)
BEGIN
	RAISERROR('Кандидатът не може да има оценка от олимпиада!',16,1)
	ROLLBACK TRANSACTION
END

IF (@fromolymp=1 AND @olympscore IS NULL)
BEGIN
	RAISERROR('Кандидатът трябва  да има оценка от олимпиада!',16,1)
	ROLLBACK TRANSACTION
END

IF (@fromolymp=0 AND @newGoTo=0)
BEGIN
	RAISERROR('Кандидатът трябва да отиде на изпит, ако няма оценка от олимпиада!',16,1)
	ROLLBACK TRANSACTION
END
-- Updating history
INSERT Wishes_History(Comment,Person_ID,Profile_ID,Priority,Score,FromOlymp,OlympScore,
	GoToExam,EntOn,EntBy)
SELECT '- Променен -',d.Person_ID,d.Profile_ID,d.Priority,d.Score,
	d.FromOlymp,d.OlympScore,d.GoToExam,EntOn,EntBy FROM deleted d

-- Updating EntOn(By) if GoToExam field is updated
SELECT @newGoTo=ins.GoToExam FROM inserted ins
SELECT @oldGoTo=d.GoToExam FROM deleted d

IF NOT (@newGoTo=@oldGoTo)
BEGIN
	UPDATE w SET w.EntOn=getdate(), w.EntBy=user_name() FROM dbo.Wishes w,deleted d
	WHERE w.Person_ID=d.Person_ID AND w.Priority=d.Priority 
END








GO
SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO

SET QUOTED_IDENTIFIER  ON    SET ANSI_NULLS  ON 
GO




CREATE TRIGGER Wishes_DelHist_TRG1 ON dbo.Wishes 
FOR DELETE
AS
DECLARE
@person integer,@prior integer,@gotoE integer

IF NOT UPDATE(Priority)
BEGIN 
INSERT Wishes_History(Comment,Person_ID,Profile_ID,Priority,Score,FromOlymp,OlympScore,
	GoToExam,EntOn,EntBy)
SELECT '- Изтрит -',d.Person_ID,d.Profile_ID,d.Priority,d.Score,
	d.FromOlymp,d.OlympScore,d.GoToExam,EntOn,EntBy FROM deleted d
END
SELECT @person=d.Person_ID,@prior=d.priority,@gotoE=d.GoToExam FROM deleted d
-- Inserting in Wishes_Deleted
IF @gotoE IS NOT NULL
BEGIN
	INSERT INTO Wishes_Deleted(Person_ID,Priority,GoToExam) VALUES (@person,@prior,@gotoE)
END

-- Updating the other (lower) Wishes

UPDATE Wishes
SET Priority=Priority-1 
WHERE Priority>@prior AND Person_ID=@person









GO
SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO

SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO




CREATE TRIGGER Check_Olymp_INS ON [Wishes] 
FOR INSERT
AS
DECLARE 
	@newGoTo bit,
	@fromolymp bit,
	@olympscore float
-- Checking Olymp datas
SELECT @fromolymp=i.FromOlymp,@olympscore=i.OlympScore,@newGoTo=i.GoToExam
FROM inserted i

IF (@fromolymp=0 AND @olympscore IS NOT NULL)
BEGIN
	RAISERROR('Кандидатът не може да има оценка от олимпиада!',16,1)
	ROLLBACK TRANSACTION
END

IF (@fromolymp=1 AND @olympscore IS NULL)
BEGIN
	RAISERROR('Кандидатът трябва  да има оценка от олимпиада!',16,1)
	ROLLBACK TRANSACTION
END

IF (@fromolymp=0 AND @newGoTo=0)
BEGIN
	RAISERROR('Кандидатът трябва да отиде на изпит, ако няма оценка от олимпиада!',16,1)
	ROLLBACK TRANSACTION
END





GO
SET QUOTED_IDENTIFIER  OFF    SET ANSI_NULLS  ON 
GO

